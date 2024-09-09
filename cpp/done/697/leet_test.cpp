#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,2,2,3,1};
  vector<int> nums2{1,2,2,3,1,4,2};
  vector<int> nums3;

  EXPECT_EQ(sol.findShortestSubArray(nums), 2);
  EXPECT_EQ(sol.findShortestSubArray(nums2), 6);
  EXPECT_EQ(sol.findShortestSubArray(nums3), 0);
}

