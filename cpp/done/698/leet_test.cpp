#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{4, 3, 2, 3, 5, 2, 1};
  int k = 4;

  EXPECT_EQ(sol.canPartitionKSubsets(nums, k), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1,1, 1,1, 1,1, 1,1, 1, 1};
  int k = 5;

  EXPECT_EQ(sol.canPartitionKSubsets(nums, k), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{4, 3, 2, 3, 5, 2, 2};
  int k = 4;

  EXPECT_EQ(sol.canPartitionKSubsets(nums, k), false);
}

