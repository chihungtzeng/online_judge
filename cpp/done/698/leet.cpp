#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (total % k != 0) return false;
    vector<int> buckets(k);
    sort(nums.begin(), nums.end());
    return helper(nums,buckets,nums.size()-1, total/k);
  }
  bool helper(vector<int>& nums, vector<int>& buckets, int idx, int avg){
    if (idx < 0){
      for(int i=0; i<buckets.size(); i++){
        if (buckets[i] != avg) return false;
      }
      return true;
    }
    for(int i=0; i<buckets.size();i++){
      if (buckets[i] + nums[idx] <= avg){
        buckets[i] += nums[idx];
        if (helper(nums, buckets, idx -1, avg)) return true;
        buckets[i] -= nums[idx];
      }
    }
    return false;
  }
};
