#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1,2,10,5,7};
  EXPECT_EQ(sol.canBeIncreasing(nums), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2,3,1,2};
  EXPECT_EQ(sol.canBeIncreasing(nums), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1,1,1};
  EXPECT_EQ(sol.canBeIncreasing(nums), false);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {10,1,2,3};
  EXPECT_EQ(sol.canBeIncreasing(nums), true);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {105,924,32,968};
  EXPECT_EQ(sol.canBeIncreasing(nums), true);
}

