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
#define DEBUG 1
using namespace std;

class LRUCache
{
  using ipair = pair<int, int>;

public:
  list<ipair> cache_;
  unordered_map<int, list<ipair>::iterator> key2iter_;
  const size_t cap_;

public:
  LRUCache(int capacity) : cap_(capacity)
  {
  }

  int get(int key)
  {
    auto it = key2iter_.find(key);
    if (it == key2iter_.end())
      return -1;

    int ret = it->second->second;
    cache_.erase(it->second);
    cache_.push_front({ key, ret });
    it->second = cache_.begin();
    return ret;
  }

  void put(int key, int value)
  {
    auto it = key2iter_.find(key);
    if (it != key2iter_.end())
    {
      cache_.erase(it->second);
      key2iter_.erase(it);
    }

    if (cache_.size() >= cap_)
    {
      auto& [k, v] = cache_.back();
      auto it = key2iter_.find(k);
      key2iter_.erase(it);
      cache_.pop_back();
    }

    cache_.push_front({ key, value });
    key2iter_[key] = cache_.begin();
  }
};
