#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1,3,1};
  EXPECT_EQ(sol.minimumMountainRemovals(nums), 0);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2,1,1,5,6,2,3,1};
  EXPECT_EQ(sol.minimumMountainRemovals(nums), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {4,3,2,1,1,2,3,1};
  EXPECT_EQ(sol.minimumMountainRemovals(nums), 4);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {1,2,3,4,4,3,2,1};
  EXPECT_EQ(sol.minimumMountainRemovals(nums), 1);
}

