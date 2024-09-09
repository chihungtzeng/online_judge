#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {2, 2, 1, 1, 5, 3, 3, 5};
  EXPECT_EQ(sol.maxEqualFreq(nums), 7);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
  EXPECT_EQ(sol.maxEqualFreq(nums), 13);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1, 1, 1, 2, 2, 2};
  EXPECT_EQ(sol.maxEqualFreq(nums), 5);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {10, 2, 8, 9, 3, 8, 1, 5, 2, 3, 7, 6};
  EXPECT_EQ(sol.maxEqualFreq(nums), 8);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 2, 7, 1,8, 2, 8, 1, 3, 1, 1, 1, 4, 1, 2};
  EXPECT_EQ(sol.maxEqualFreq(nums), 8);
}

