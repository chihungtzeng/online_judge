#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {3, 1, 4, 2};
  int p = 6;
  EXPECT_EQ(sol.minSubarray(nums, p), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {6, 3, 5, 2};
  int p = 9;
  EXPECT_EQ(sol.minSubarray(nums, p), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  int p = 3;
  EXPECT_EQ(sol.minSubarray(nums, p), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  int p = 7;
  EXPECT_EQ(sol.minSubarray(nums, p), -1);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {1000000000, 1000000000, 1000000000};
  int p = 3;
  EXPECT_EQ(sol.minSubarray(nums, p), 0);
}

