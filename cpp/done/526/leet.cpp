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

class Solution
{
public:
  int countArrangement(int n)
  {
    vector<vector<int>> cans(n + 1);
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i % j == 0 || j % i == 0)
        {
          cans[i].push_back(j);
        }
      }
    }
    int pick = 0;
    return helper(n, cans, pick);
  }
  int helper(int idx, vector<vector<int>>& cans, int pick)
  {
    if (idx == 0)
    {
      return 1;
    }

    int ans = 0;
    for (auto val : cans[idx])
    {
      int mask = (1 << val);
      if (pick & mask)
      {
        continue;
      }
      pick |= mask;
      ans += helper(idx - 1, cans, pick);
      pick ^= mask;
    }
    return ans;
  }
};
