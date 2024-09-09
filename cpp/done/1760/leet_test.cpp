#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {9};
  int maxOperations = 2;
  EXPECT_EQ(sol.minimumSize(nums, maxOperations), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2, 4, 8, 2};
  int maxOperations = 4;
  EXPECT_EQ(sol.minimumSize(nums, maxOperations), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {7, 17};
  int maxOperations = 2;
  EXPECT_EQ(sol.minimumSize(nums, maxOperations), 7);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {1, 1, 1, 1};
  int maxOperations = 10000;
  EXPECT_EQ(sol.minimumSize(nums, maxOperations), 1);
}

