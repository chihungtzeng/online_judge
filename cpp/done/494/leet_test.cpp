#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1, 1, 1, 1, 1};

  EXPECT_EQ(sol.findTargetSumWays(nums, 3), 5);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums;

  EXPECT_EQ(sol.findTargetSumWays(nums, 0), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums;
  for(int i=0; i<20; i++){
    nums.push_back(i+1);
  }

  EXPECT_EQ(sol.findTargetSumWays(nums, 10), 15029);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};

  EXPECT_EQ(sol.findTargetSumWays(nums, 2147483647), 0);
}


