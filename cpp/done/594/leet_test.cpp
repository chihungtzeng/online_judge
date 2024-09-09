#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1,3,2,2,5,2,3,7};
  EXPECT_EQ(sol.findLHS(nums), 5);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1,2,3,4};
  EXPECT_EQ(sol.findLHS(nums), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1,1,1,1};
  EXPECT_EQ(sol.findLHS(nums), 0);
}

