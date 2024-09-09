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
    vector<int> nums(n), div(n);
    for(int i=1; i<=n; i++){
      nums[i-1] = i;
      div[i-1] = i;
    }
    int ans = 0;
    do
    {
      ans += is_beautiful(nums, div);
    } while(next_permutation(nums.begin(), nums.end()));
    return ans;
  }
  int is_beautiful(vector<int>& nums, vector<int>& div)
  {
    for(int i=nums.size()-1; i>=0; i--)
    {
      if (nums[i] % div[i] == 0 || div[i] % nums[i] == 0) {
      }
      else {
        return 0;
      }
    }
    return 1;
  }

};
