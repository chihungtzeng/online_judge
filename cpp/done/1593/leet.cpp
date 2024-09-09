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

class Solution {
 public:
  unsigned long best_;
  int maxUniqueSplit(string s) {
    best_ = 0;
    unordered_set<string> cache;
    dfs(s, cache, string{s[0]}, 1);

    return best_;
  }
  void dfs(string& s, unordered_set<string>& cache, string last,
           const int pos) {
    if (pos == s.size()) {
      if (cache.find(last) == cache.end()) {
        cache.insert(last);
        if (cache.size() > best_) {
          best_ = cache.size();
#if 0
          LOG(INFO) << "update best_: " << best_;
          for (auto& item : cache) {
            LOG(INFO) << item;
          }
#endif
        }
        cache.erase(cache.find(last));
      }
      return;
    }
    string temp = last + s[pos];
    if (cache.find(temp) == cache.end()) {
      dfs(s, cache, temp, pos + 1);
    }
    temp = s[pos];
    if (cache.find(last) == cache.end()) {
      cache.insert(last);
      dfs(s, cache, temp, pos + 1);
      cache.erase(cache.find(last));
    }
  }
};
