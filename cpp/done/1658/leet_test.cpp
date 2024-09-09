#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 1, 4, 2, 3};
  int x = 5;
  EXPECT_EQ(sol.minOperations(nums, x), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {5, 6, 7, 8, 9};
  int x = 4;
  EXPECT_EQ(sol.minOperations(nums, x), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {3, 2, 20, 1, 1, 3};
  int x = 10;
  EXPECT_EQ(sol.minOperations(nums, x), 5);
}

