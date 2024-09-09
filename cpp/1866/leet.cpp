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

constexpr int base = 1e9 + 7;
vector<int64_t> factorial(1001);
class Solution {
 public:
  int rearrangeSticks(int n, int k) {
    factorial[0] = 1;
    for(int i=1; i<1001; i++){
      factorial[i] = (i * factorial[i-1]) % base;
    }
    vector<vector<int64_t>> ans(n+1, vector<int64_t>(n+1));
    ans[1][1] = 1;
    for(int i=2; i<=n; i++){
      ans[i][1] = factorial[i-1];
      for(int j=2; j<=k; j++){
        ans[i][j] = helper(ans, i, j);
      }
    }
    return ans[n][k];
  }
  int64_t helper(vector<vector<int64_t>>& ans, int i, int j)
  {
    int64_t res = 0;
    for(int m=j-1; m<=i-1; m++)
    {
      res = (res + ans[m][j-1] * factorial[i - 1 - m]) % base;
    }
    return res;
  }
};
