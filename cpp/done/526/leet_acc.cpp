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
    set<int> pick;
    return helper(n, cans, pick);
  }
  int helper(int idx, vector<vector<int>>& cans, set<int>& pick)
  {
    if (idx == 0)
    {
      return 1;
    }

    int ans = 0;
    for (auto val : cans[idx])
    {
      if (pick.count(val) > 0)
        continue;
      pick.insert(val);
      ans += helper(idx - 1, cans, pick);
      pick.erase(val);
    }
    return ans;
  }
};
