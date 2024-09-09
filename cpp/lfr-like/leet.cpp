#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <memory>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
  string key_;
  int freq_;
  list<shared_ptr<Node>>::const_iterator it_;
  Node() = default;
  Node(string key) : key_(key), freq_(1) {}
};

class AllOne {
 public:
  unordered_map<string, shared_ptr<Node>> node_cache_;
  unordered_map<int, list<shared_ptr<Node>>> freq2nodes_;

  AllOne() {}
  void inc(string key) {
    auto it = node_cache_.find(key);
    if (it == node_cache_.end()) {
      shared_ptr<Node> node(new Node{key});
      node_cache_[key] = node;

      freq2nodes_[1].push_front(node);
      node->it_ = freq2nodes_[1].cbegin();
      return;
    }
    int freq = it->second->freq_;
    freq2nodes_[freq].erase(it->second->it_);
    it->second->freq_ += 1;
    freq++;
    freq2nodes_[freq].push_front(it->second);
    it->second->it_ = freq2nodes_[freq].cbegin();
  }
  void dump() {
    LOG(INFO) << "node_cache_";
    for (auto& [key, node] : node_cache_) {
      LOG(INFO) << "  " << &node << ":" << node->key_ << ", " << node->freq_ << ", "  << &(node->it_);
    }
    LOG(INFO) << "freq2nodes_";
    for (auto& [key, freqlist] : freq2nodes_) {
      LOG(INFO) << "Freq: " << key;
      for(auto& node: freqlist) {
        LOG(INFO) << "  " << &node << ":" << node->key_ << ", " << node->freq_
                  << ", " << &(node->it_);
      }
    }
  }
};
