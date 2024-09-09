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
class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    const int n = piles.size();
    if (n == 1) return piles[0];
    for (int i = 1; i < n; i++) {
      piles[i] += piles[i - 1];
    }
    map<ipair, ipair> cache;
    auto [alice, bob] = helper(0, 1, cache, piles);
    return alice;
  }
  int range_sum(vector<int>& psum, int i, int j) {
    if (i == 0) return psum[j];
    else if (j < psum.size()){
      return psum[j] - psum[i - 1];
    } else {
      return psum.back() - psum[i - 1];
    }
  }
  ipair helper(int idx, int m, map<ipair, ipair>& cache, vector<int>& psum) {
    if (idx >= psum.size()) return {0, 0};
    ipair key{idx, m};
    auto it = cache.find(key);
    if (it != cache.end()) return it->second;

    int alice = 0;
    for (int take = 1, ub = m * 2; take <= ub; take++) {
      if (idx + take < psum.size()) {
        auto [b, a] = helper(idx + take, max(m, take), cache, psum);
        alice = max(alice, a + range_sum(psum, idx, idx + take - 1));
      } else {
        alice = max(alice, range_sum(psum, idx, idx + take));
      }
    }
    int bob = range_sum(psum, idx, psum.size() - 1) - alice;
    cache[key] = {alice, bob};
    return {alice, bob};
  }
};
