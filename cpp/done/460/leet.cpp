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

#define DEBUG 0

struct CacheItem {
  int key_, val_, freq_;
  CacheItem(int k, int v, int f) : key_(k), val_(v), freq_(f) {}
  CacheItem(int k, int v) : key_(k), val_(v), freq_(1) {}
  string str() const {
    return "(" + to_string(key_) + ", " + to_string(val_) + ")";
  }
};

class LFUCache {
 public:
  unordered_map<int, list<CacheItem>> cache_line_;  // key: list
  unordered_map<int, list<CacheItem>::iterator> cache_item_pos_;
  int min_freq_;
  int cap_;
  LFUCache(int capacity) : min_freq_(0), cap_(capacity) {}

  int get(int key) {
    auto it = cache_item_pos_.find(key);
    if (it == cache_item_pos_.end()) {
      return -1;
    }
    CacheItem item = *(it->second);
    auto org_freq = item.freq_;
    item.freq_ += 1;
    cache_line_[org_freq].erase(it->second);
    cache_line_[org_freq + 1].insert(cache_line_[org_freq + 1].begin(), item);
    cache_item_pos_[key] = cache_line_[org_freq + 1].begin();
    if (cache_line_[org_freq].empty() && org_freq == min_freq_) {
      min_freq_ = org_freq + 1;
    }
    return it->second->val_;
  }

  void put(int key, int value) {
#if DEBUG
    LOG(INFO) << "before put " << pair<int, int>{key, value};
    for (auto& [f, ell] : cache_line_) {
      if (!ell.empty()) {
        std::cout << f << ": ";
        for (auto& item : ell) {
          std::cout << item.str() << " ";
        }
        std::cout << std::endl;
      }
    }
#endif
    if (cap_ == 0) return;

    if (get(key) != -1) {
      auto it = cache_item_pos_.find(key);
      it->second->val_ = value;
      return;
    }

    if (cache_item_pos_.size() == cap_) {
      auto to_del_key = cache_line_[min_freq_].back().key_;
      auto it = cache_item_pos_.find(to_del_key);
      cache_line_[min_freq_].pop_back();
      cache_item_pos_.erase(it);
    }
    min_freq_ = 1;
    cache_line_[1].push_front(CacheItem(key, value, 1));
    cache_item_pos_[key] = cache_line_[1].begin();
#if DEBUG
    LOG(INFO) << "after put " << pair<int, int>{key, value};
    for (auto& [f, ell] : cache_line_) {
      if (!ell.empty()) {
        std::cout << f << ": ";
        for (auto& item : ell) {
          std::cout << item.str() << " ";
        }
        std::cout << std::endl;
      }
    }
#endif
  }
};

