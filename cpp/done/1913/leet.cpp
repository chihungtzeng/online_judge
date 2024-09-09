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
  int maxProductDifference(vector<int>& nums)
  {
    priority_queue<int, vector<int>, greater<>> min_pq;
    priority_queue<int> max_pq;

    for (int i = 0; i < 2; i++)
    {
      min_pq.push(nums[i]);
      max_pq.push(nums[i]);
    }

    for (int i = 2, n = nums.size(); i < n; i++)
    {
      int v = nums[i];
      if (v < max_pq.top())
      {
        max_pq.pop();
        max_pq.push(v);
      }
      if (v > min_pq.top())
      {
        min_pq.pop();
        min_pq.push(v);
      }
    }
    int small = 1, large = 1;
    for (int i = 0; i < 2; i++)
    {
      small *= max_pq.top();
      max_pq.pop();
      large *= min_pq.top();
      min_pq.pop();
    }
    return large - small;
  }
};
