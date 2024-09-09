#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1, 5,11,5};
  EXPECT_TRUE(sol.canPartition(nums));
  vector<int> nums2{1, 2,3,5};
  EXPECT_FALSE(sol.canPartition(nums2));
  vector<int> nums3{4};
  EXPECT_FALSE(sol.canPartition(nums3));
  vector<int> nums4{1,2,5};
  EXPECT_FALSE(sol.canPartition(nums4));
}

