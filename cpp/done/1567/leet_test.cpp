#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, -2, -3, 4};
  EXPECT_EQ(sol.getMaxLen(nums), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {0, 1, -2, -3, -4};
  EXPECT_EQ(sol.getMaxLen(nums), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {-1, -2, -3, 0, 1};
  EXPECT_EQ(sol.getMaxLen(nums), 2);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {-1, 2};
  EXPECT_EQ(sol.getMaxLen(nums), 1);
}

TEST(kk, t4_1) {
  Solution sol;
  vector<int> nums = {-1, 2, 3};
  EXPECT_EQ(sol.getMaxLen(nums), 2);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 5, -6, 4, 0, 10};
  EXPECT_EQ(sol.getMaxLen(nums), 4);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> nums = {17, 0, 17, 0, 5, -10, -15, 13, -14, -3};
  EXPECT_EQ(sol.getMaxLen(nums), 6);
}

