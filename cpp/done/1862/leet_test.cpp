#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {2, 5, 9};
  EXPECT_EQ(sol.sumOfFlooredPairs(nums), 10);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
  EXPECT_EQ(sol.sumOfFlooredPairs(nums), 49);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1, 1, 2};
  EXPECT_EQ(sol.sumOfFlooredPairs(nums), 9);
}

