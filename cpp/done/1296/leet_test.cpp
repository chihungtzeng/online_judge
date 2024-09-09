#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 3, 4, 4, 5, 6};
  int k = 4;
  EXPECT_EQ(sol.isPossibleDivide(nums, k), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11};
  int k = 3;
  EXPECT_EQ(sol.isPossibleDivide(nums, k), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {3, 3, 2, 2, 1, 1};
  int k = 3;
  EXPECT_EQ(sol.isPossibleDivide(nums, k), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};
  int k = 3;
  EXPECT_EQ(sol.isPossibleDivide(nums, k), false);
}

