#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,1,2,2,2};

  EXPECT_EQ(sol.makesquare(nums), true);

  vector<int> nums2{3,3,3,3,4};
  EXPECT_EQ(sol.makesquare(nums2), false);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums;
  EXPECT_EQ(sol.makesquare(nums), false);
}

