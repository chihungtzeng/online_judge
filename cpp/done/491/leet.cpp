#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findSubsequences(const vector<int>& nums)
  {
    vector<vector<int>> res;
    int comb = (1 << nums.size()) - 1;
    while (comb >= 3)
    {
      vector<int> cur;
      cur.reserve(nums.size());
      int i = 0;
      bool done = false;
      while (!done && (comb >> i) > 0)
      {
        if ((comb >> i) & 1)
        {
          if (cur.empty() || (nums[i] >= cur.back())) {
            cur.push_back(nums[i]);
          }
          else {
            done = true;
          }
        }
        i++;
      }
      comb--;
      if (cur.size() >= 2)
      {
        res.emplace_back(cur);
      }
    }
    return res;
  }
};
