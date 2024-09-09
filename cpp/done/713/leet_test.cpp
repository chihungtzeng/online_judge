#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{10, 5, 2, 6};
  int k = 100;

  EXPECT_EQ(sol.numSubarrayProductLessThanK(nums, k), 8);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1,1,1};
  int k = 0;

  EXPECT_EQ(sol.numSubarrayProductLessThanK(nums, k), 0);
  EXPECT_EQ(sol.numSubarrayProductLessThanK(nums, 1), 0);
  EXPECT_EQ(sol.numSubarrayProductLessThanK(nums, 2), 6);
}

