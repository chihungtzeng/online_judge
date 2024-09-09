#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {12, 5, 7, 23};
  EXPECT_EQ(sol.isGoodArray(nums), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {29, 6, 10};
  EXPECT_EQ(sol.isGoodArray(nums), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {3, 6};
  EXPECT_EQ(sol.isGoodArray(nums), false);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {6, 10, 15};
  EXPECT_EQ(sol.isGoodArray(nums), true);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {3,3,3,3,3,3,3,3,3};
  EXPECT_EQ(sol.isGoodArray(nums), false);
}

