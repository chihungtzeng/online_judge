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
    priority_queue<int> lpq{nums.begin(), nums.begin() + n};
    priority_queue<int, vector<int>, greater<int>> rpq{nums.begin() + 2*n, nums.end()}
    long long lsum = accumulate(nums.begin()
    for(int i=0; i<n; i++)
    {
    }

  }
  
};
