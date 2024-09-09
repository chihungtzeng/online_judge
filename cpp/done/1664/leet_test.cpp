#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {2, 1, 6, 4};
  EXPECT_EQ(sol.waysToMakeFair(nums), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1, 1, 1};
  EXPECT_EQ(sol.waysToMakeFair(nums), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  EXPECT_EQ(sol.waysToMakeFair(nums), 0);
}

TEST(kk, t4) {
  Solution sol;

  vector<int> nums = {3, 1, 3, 1, 5, 9, 2, 6, 2, 7, 1, 8, 2, 8};
  EXPECT_EQ(sol.waysToMakeFair(nums), 0);
}

