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
  int minimumCost(vector<int>& cost)
  {
    priority_queue<int> pq{ cost.begin(), cost.end() };
    int ans = 0;
    while (!pq.empty())
    {
      ans += pq.top();
      pq.pop();
      if (!pq.empty())
      {
        ans += pq.top();
        pq.pop();
      }
      if (!pq.empty())
      {
        pq.pop();
      }
    }
    return ans;
  }
};
