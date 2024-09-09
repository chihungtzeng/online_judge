#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{23, 2, 4, 6, 7};

  EXPECT_EQ(sol.checkSubarraySum(nums, 0), false);
  EXPECT_EQ(sol.checkSubarraySum(nums, 1), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 2), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 3), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 4), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 5), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 6), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 7), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 8), false);
  EXPECT_EQ(sol.checkSubarraySum(nums, 9), false);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{0, 0};

  EXPECT_EQ(sol.checkSubarraySum(nums, 0), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 1), true);
  EXPECT_EQ(sol.checkSubarraySum(nums, 2), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{0, 1, 0};

  EXPECT_EQ(sol.checkSubarraySum(nums, 0), false);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{1, 0};

  EXPECT_EQ(sol.checkSubarraySum(nums, 2), false);
}

