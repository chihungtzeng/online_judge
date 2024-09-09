#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
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
  Node(string key) : key_(key), freq_(1) {}
};

class AllOne {
 public:
  unordered_map<string, shared_ptr<Node>> node_cache_;
  map<int, list<shared_ptr<Node>>> freq2nodes_;

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

    if (freq2nodes_[freq].empty()) {
      freq2nodes_.erase(freq);
    }

    it->second->freq_ += 1;
    freq++;
    freq2nodes_[freq].push_front(it->second);
    it->second->it_ = freq2nodes_[freq].cbegin();
  }
  void dec(string key) {
    auto it = node_cache_.find(key);
    if (it == node_cache_.end()) {
      return;
    }
    int freq = it->second->freq_;
    freq2nodes_[freq].erase(it->second->it_);
    if (freq2nodes_[freq].empty()) {
      freq2nodes_.erase(freq);
    }
    freq = --(it->second->freq_);
    if (freq == 0) {
      node_cache_.erase(it);
    } else {
      freq2nodes_[freq].push_front(it->second);
      it->second->it_ = freq2nodes_[freq].cbegin();
    }
  }
  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    if (freq2nodes_.empty()) return "";
    auto it = freq2nodes_.rbegin();
    return (it->second).front()->key_;
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    if (freq2nodes_.empty()) return "";
    auto it = freq2nodes_.begin();
    return (it->second).front()->key_;
  }
#if 0
  void dump() {
    LOG(INFO) << "node_cache_";
    for (auto& [key, node] : node_cache_) {
      LOG(INFO) << "  " << &node << ":" << node->key_ << ", " << node->freq_
                << ", " << &(node->it_);
    }
    LOG(INFO) << "freq2nodes_";
    for (auto& [key, freqlist] : freq2nodes_) {
      LOG(INFO) << "Freq: " << key;
      for (auto& node : freqlist) {
        LOG(INFO) << "  " << &node << ":" << node->key_ << ", " << node->freq_
                  << ", " << &(node->it_);
      }
    }
  }
#endif
};
