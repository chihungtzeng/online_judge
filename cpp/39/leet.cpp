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
  vector<vector<int>> combinationSum(vector<int>& cans, int target)
  {
    sort(cans.begin(), cans.end());
    vector<vector<int>> ans;
    for (int i = 0; i < cans.size(); i++)
    {
      vector<int> visits{ cans[i] };
      helper(cans, target, i, visits, cans[i], ans);
    }
    return ans;
  }
  void helper(vector<int>& cans, int target, int idx, vector<int>& visits, int acc, vector<vector<int>>& ans)
  {
    if (acc == target)
    {
      ans.push_back(visits);
      return;
    }
    for (int i = idx; i < cans.size() && acc + cans[i] <= target; i++)
    {
      visits.push_back(cans[i]);
      helper(cans, target, i, visits, acc + cans[i], ans);
      visits.pop_back();
    }
  }
};
