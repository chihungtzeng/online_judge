#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};
  int k = 5;
  EXPECT_EQ(sol.maxOperations(nums, k), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {3, 1, 3, 4, 3};
  int k = 6;
  EXPECT_EQ(sol.maxOperations(nums, k), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {3,1,5,1,1,1,1,1,2,2,3,2,2};

  int k = 1;
  EXPECT_EQ(sol.maxOperations(nums, k), 0);
}

