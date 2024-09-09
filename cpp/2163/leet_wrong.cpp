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
  long long minimumDifference(vector<int>& nums)
  {
    const int n = nums.size() / 3;
    multiset<int> lvals{ nums.begin(), nums.begin() + n }, rvals{ nums.begin() + n, nums.begin() + 2 * n };
    deque<int> q{ nums.begin() + n, nums.begin() + 2 * n };
    multiset<int> rys;

    for (int i = 2 * n; i < nums.size(); i++)
    {
      int x = *lvals.rbegin();
      while (!q.empty() && !rys.empty() && rys.count(q.front()) > 0)
      {
        rys.erase(rys.find(q.front()));
        q.pop_front();
      }
      int qf = q.front();
      int diff1 = -x + 2 * qf - nums[i];

      // case 2
      int y = *rvals.begin();
      int diff2 = y - nums[i];
      if (diff1 < 0 || diff2 < 0)
      {
        if (diff1 <= diff2)
        {
          lvals.erase(lvals.find(x));
          lvals.insert(qf);
          q.pop_front();
          rvals.erase(rvals.find(qf));
          rvals.insert(nums[i]);
          q.push_back(nums[i]);
        }
        else
        {
          rvals.erase(rvals.find(y));
          rys.insert(y);
          q.push_back(nums[i]);
          rvals.insert(nums[i]);
        }
      }
    }
    long long left = accumulate(lvals.begin(), lvals.end(), 0LL);
    long long right = accumulate(rvals.begin(), rvals.end(), 0LL);

    return left - right;
  }
};
