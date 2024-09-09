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

class Solution {
 public:
  string kthSmallestPath(vector<int>& dest, int k) {
    vector<vector<int64_t>> cache(31, vector<int64_t>(31));
    int nv = dest[0];
    int nh = dest[1];
    string ans;
    while (nh + nv >= 1) {
      if (nh == 0 && nv > 0) {
        ans.push_back('V');
        nv--;
      } else if (nv == 0 && nh > 0) {
        ans.push_back('H');
        nh--;
      } else {
        int64_t comb = choose(nh + nv - 1, nh - 1, cache);
        if (k <= comb) {
          ans.push_back('H');
          nh--;
        } else {
          ans.push_back('V');
          nv--;
          k -= comb;
        }
      }
    }
    return ans;
  }
  int64_t choose(int a, int b, vector<vector<int64_t>>& cache) {
    if (cache[a][b] > 0) return cache[a][b];
    if (a == 0 || b == 0 || a == b) {
      cache[a][b] = 1;
      return 1;
    }
    cache[a][b] = choose(a - 1, b, cache) + choose(a - 1, b - 1, cache);
    return cache[a][b];
  }
};
