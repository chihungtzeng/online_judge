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

private:
  list<ipair> cache;
  unordered_map<int, list<ipair>::iterator> it_map;
  const int cap;

public:
  LRUCache(int capacity) : cap(capacity)
  {
  }

  int get(int key)
  {
    auto it = it_map.find(key);
    if (it == it_map.end())
    {
      return -1;
    }
    const int res = it->second->second;
    cache.erase(it->second);
    // cache.insert(cache.begin(), {key, res});
    cache.emplace_front(ipair{ key, res });
    it->second = cache.begin();
    return res;
  }

  void put(int key, int val)
  {
    auto it = it_map.find(key);
    if (it == it_map.end())
    {
      // cache.insert(cache.begin(), { key, val });
      cache.emplace_front(ipair{ key, val });
      it_map[key] = cache.begin();
    }
    else
    {
      cache.erase(it->second);
      // cache.insert(cache.begin(), {key, val});
      cache.emplace_front(ipair{ key, val });
      it->second = cache.begin();
    }

    if (cache.size() > cap)
    {
      auto [key, val] = cache.back();
      cache.pop_back();
      it_map.erase(key);
    }
  }
};
