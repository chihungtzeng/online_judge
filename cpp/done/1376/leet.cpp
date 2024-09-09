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

class Solution
{
public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
  {
    vector<vector<int>> subs(n);
    for (int i = 0; i < n; i++)
    {
      if (manager[i] >= 0)
      {
        subs[manager[i]].push_back(i);
      }
    }
    int ans = -1;
    dfs(subs, informTime, headID, 0, &ans);
    return ans;
  }
  void dfs(vector<vector<int>>& subs, vector<int>& informTime, int cur, int delay, int* ans)
  {
    *ans = max(*ans, delay);
    for (auto sub : subs[cur])
    {
      dfs(subs, informTime, sub, delay + informTime[cur], ans);
    }
  }
};
