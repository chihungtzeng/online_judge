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
  vector<int> decode(vector<int>& encoded) {
    const int n = encoded.size() + 1;
    vector<int> b = encoded;
    int n_1 = n - 1;
    int a1_n = b[0];
    for (int i = 1; i < n_1; i++) {
      b[i] ^= b[i - 1];
      a1_n ^= b[i];
    }
    int all_xor = 0;
    for (int i = 1; i <= n; i++) {
      all_xor ^= i;
    }
    vector<int> ans(n);
    ans[0] = all_xor ^ a1_n;
    for (int i = 1; i < n; i++) {
      ans[i] = ans[i - 1] ^ encoded[i-1];
    }
    return ans;
  }
};
