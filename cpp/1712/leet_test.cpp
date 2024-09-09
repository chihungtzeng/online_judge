#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 1, 1};
  EXPECT_EQ(sol.waysToSplit(nums), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1, 2, 2, 2, 5, 0};
  EXPECT_EQ(sol.waysToSplit(nums), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {3, 2, 1};
  EXPECT_EQ(sol.waysToSplit(nums), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {2,3,5,10};
  EXPECT_EQ(sol.waysToSplit(nums), 3);
}

