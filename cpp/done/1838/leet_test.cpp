#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = { 1, 2, 4 };
  int k = 5;
  EXPECT_EQ(sol.maxFrequency(nums, k), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = { 1, 4, 8, 13 };
  int k = 5;
  EXPECT_EQ(sol.maxFrequency(nums, k), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = { 3, 9, 6 };
  int k = 2;
  EXPECT_EQ(sol.maxFrequency(nums, k), 1);
}

