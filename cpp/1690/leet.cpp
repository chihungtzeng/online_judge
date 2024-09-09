#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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

using ipair = pair<int, int>;
using ituple = tuple<int, int, bool>;
class Solution {
 public:
  int stoneGameVII(vector<int> &stones) {
    map<ituple, int> cache;
    vector<int> psum(stones.size());
    psum[0] = stones[0];
    for (int i = 1; i < stones.size(); i++) {
      psum[i] = psum[i - 1] + stones[i];
    }
    return helper(psum, cache, 0, stones.size() - 1, true);
  }

  int range_sum(vector<int> &psum, int from, int to) {
    if (from == 0)
      return psum[to];
    else
      return psum[to] - psum[from - 1];
  }

  int helper(vector<int> &psum, map<ituple, int> &cache, const int from,
             const int to, bool alice_turn) {
    if (from >= to) return 0;

    ituple key{from, to, alice_turn};
    auto it = cache.find(key);
    if (it != cache.end()) {
      return it->second;
    }

    if (alice_turn) {
      int left = range_sum(psum, from + 1, to) +
                 helper(psum, cache, from + 1, to, !alice_turn);
      int right = range_sum(psum, from, to - 1) +
                  helper(psum, cache, from, to - 1, !alice_turn);
      int ret = max(left, right);
      cache[key] = ret;
      return ret;
    } else {
      int left = -range_sum(psum, from + 1, to) +
                 helper(psum, cache, from + 1, to, !alice_turn);
      int right = -range_sum(psum, from, to - 1) +
                  helper(psum, cache, from, to - 1, !alice_turn);
      int ret = min(left, right);
      cache[key] = ret;
      return ret;
    }
  }
};
