#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

int naive(vector<int>& nums) {
  int ret = 0;
  for(int i=0; i<nums.size(); i++){
    for(int j=i+1; j<nums.size(); j++){
      ret = max(ret, nums[i]^nums[j]);
    }
  }
  return ret;
}

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{3, 10, 5, 25, 2, 8};

  EXPECT_EQ(sol.findMaximumXOR(nums), 28);
  EXPECT_EQ(naive(nums), 28);
}

TEST(kk, t2) {
  Solution sol;
  int k=5000;
  vector<int> nums(k);
  for(int i=0; i<k; i++){
    nums[i] = rand() % 0x7fffffff;
  }

  EXPECT_EQ(sol.findMaximumXOR(nums), naive(nums));
}

