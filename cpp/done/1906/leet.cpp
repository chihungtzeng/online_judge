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
  vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries)
  {
    vector<vector<int>> seen(101);
    for(int i=0; i<seen.size(); i++){
      seen.reserve(1024);
    }
    for (int i = 0; i < nums.size(); i++)
    {
      seen[nums[i]].push_back(i);
    }
    vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); i++)
    {
      int left = queries[i][0];
      int right = queries[i][1];
      vector<int> vals;
      vals.reserve(100);
      for (int val = 1; val <= 100; val++)
      {
        auto it = lower_bound(seen[val].begin(), seen[val].end(), left);
        if (it != seen[val].end() && *it <= right)
        {
          vals.push_back(val);
        }
      }
      if (vals.size() <= 1)
      {
        res[i] = -1;
      }
      else
      {
        int temp = vals[1] - vals[0];
        int prev = vals[1];
        for (int i = 2; i < vals.size(); i++)
        {
          temp = min(temp, vals[i] - prev);
          prev = vals[i];
        }
        res[i] = temp;
      }
    }
    return res;
  }
};
