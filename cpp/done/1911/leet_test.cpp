#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {4,2,5,3};
  EXPECT_EQ(sol.maxAlternatingSum(nums), 7);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {5,6,7,8};
  EXPECT_EQ(sol.maxAlternatingSum(nums), 8);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {6,2,1,2,4,5};
  EXPECT_EQ(sol.maxAlternatingSum(nums), 10);
}

