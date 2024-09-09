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

using ituple = tuple<int, int, int>;
class Solution {
 public:
  int m_, n_, target_;
  vector<int> houses_;
  vector<vector<int>> cost_;
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
              int target) {
    m_ = m;
    n_ = n;
    target_ = target;
    swap(houses_, houses);
    swap(cost_, cost);
    map<ituple, int> cache;
    int ret = helper(0, 0, cache, 0);
    if (ret == INT_MAX) return -1;
    return ret;
  }
  int helper(int h, int nnbh, map<ituple, int>& cache, int last_color) {
    if (h >= m_ || nnbh > target_ || m_ - h < target_ - nnbh) {
      if (nnbh == target_ && h == m_)
        return 0;
      else
        return INT_MAX;
    }

    ituple key{h, last_color, nnbh};
    auto it = cache.find(key);
    if (it != cache.end()) return it->second;

    if (houses_[h] != 0) {
      int temp =
          helper(h + 1, nnbh + (houses_[h] != last_color), cache, houses_[h]);
      cache[key] = temp;
      return temp;
    }
    int ret = INT_MAX;
    for (int c = 1; c <= n_; c++) {
      int next_nnbh = (c == last_color) ? nnbh : nnbh + 1;

      int temp = helper(h + 1, next_nnbh, cache, c);
      if (temp < INT_MAX) {
        ret = min(ret, cost_[h][c - 1] + temp);
      }
    }
    cache[key] = ret;
    return ret;
  }
};
