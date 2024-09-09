#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

const int base = 1e9 + 7;
int64_t dp[100001][2][3];
class Solution
{
public:
  int checkRecord(int n)
  {
    if (n == 1)
      return 3;
    if (n == 2)
      return 8;
    memset(dp, 0, sizeof(int64_t) * 100001 * 2 * 3);
    dp[2][0][0] = 2;
    dp[2][0][1] = 1;
    dp[2][0][2] = 1;
    dp[2][1][0] = 3;
    dp[2][1][1] = 1;
    for (int i = 3; i <= n; i++)
    {
      const int i1 = i - 1;
      dp[i][0][0] = (dp[i1][0][0] + dp[i1][0][1] + dp[i1][0][2]) % base;
      dp[i][0][1] = dp[i1][0][0];
      dp[i][0][2] = dp[i1][0][1];
      dp[i][1][0] = (dp[i1][0][0] + dp[i1][0][1] + dp[i1][0][2] + dp[i1][1][0] + dp[i1][1][1] + dp[i1][1][2]) % base;
      dp[i][1][1] = dp[i1][1][0];
      dp[i][1][2] = dp[i1][1][1];
    }
    int64_t ans = 0;
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        ans += dp[n][i][j];
      }
    }
    ans %= base;
    return ans;
  }
};
