#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {2, 3, 4, 6};
  EXPECT_EQ(sol.tupleSameProduct(nums), 8);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1, 2, 4, 5, 10};
  EXPECT_EQ(sol.tupleSameProduct(nums), 16);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {2, 3, 4, 6, 8, 12};
  EXPECT_EQ(sol.tupleSameProduct(nums), 40);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {2, 3, 5, 7};
  EXPECT_EQ(sol.tupleSameProduct(nums), 0);
}

