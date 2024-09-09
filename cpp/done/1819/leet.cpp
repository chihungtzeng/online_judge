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
  int countDifferentSubsequenceGCDs(vector<int>& nums) {
    vector<int> gcds(200001);
    int largest = 0;
    for (auto v : nums) {
      for (int i = 1; i * i <= v; i++) {
        if (v % i != 0) continue;
        int f2 = v / i;
        gcds[i] = gcd(gcds[i], v);
        gcds[f2] = gcd(gcds[f2], v);
      }
      largest = max(largest, v);
    }
    int ans = 0;
    for (int i = 1; i <= largest; i++) {
      if (gcds[i] == i) {
        ans++;
      }
    }
    return ans;
  }
};

