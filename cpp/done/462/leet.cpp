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

class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int total = 0, left=0, right=nums.size()-1;
    while(left < right){
      total += nums[right--] - nums[left++];
    }
    return total;
  }
};
