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
  vector<int> maxScoreIndices(vector<int>& nums)
  {
    int n1 = 0, n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
      if (nums[i] == 1)
        n1++;
    }
    int n0 = 0;
    map<int, vector<int>> scores;
    for (int i = 0; i < n; i++)
    {
      scores[n0 + n1].push_back(i);
      if (nums[i] == 0)
        n0++;
      else if (nums[i] == 1)
        n1--;
    }
    scores[n0].push_back(n);
    return scores.rbegin()->second;
  }
};
