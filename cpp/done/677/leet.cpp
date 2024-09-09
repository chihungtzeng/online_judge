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

class TrieNode {
 public:
  unordered_map<char, TrieNode *> chs_;
  int sum_;
  TrieNode() : sum_(0){};
  ~TrieNode() {
    for (auto &[key, val] : chs_) {
      delete val;
    }
    chs_.clear();
  }
};

class MapSum {
 public:
  /** Initialize your data structure here. */
  TrieNode *root_;
  unordered_map<string, int> kvs_;
  MapSum() : root_(new TrieNode()) {}

  void insert(string key, int val) {
    auto it = kvs_.find(key);
    int offset = val;
    if (it != kvs_.end()) {
      offset = val - it->second;
    }
    kvs_[key] = val;
    TrieNode *cur = root_;
    for (auto ch : key) {
      cur->sum_ += offset;
      if (cur->chs_.find(ch) == cur->chs_.end()) {
        cur->chs_[ch] = new TrieNode();
      }
      cur = cur->chs_[ch];
    }
    cur->sum_ += offset;
  }

  int sum(string prefix) {
    TrieNode *cur = root_;
    for (auto ch : prefix) {
      if (cur->chs_.find(ch) == cur->chs_.end()) {
        return 0;
      }
      cur = cur->chs_[ch];
    }
    return cur->sum_;
  }
  ~MapSum() { delete root_; }
};

