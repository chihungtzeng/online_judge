#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 2, 1, 4};
  int k = 2;
  EXPECT_EQ(sol.minimumIncompatibility(nums, k), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {6, 3, 8, 1, 3, 1, 2, 2};
  int k = 4;
  EXPECT_EQ(sol.minimumIncompatibility(nums, k), 6);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {5, 3, 3, 6, 3, 3};
  int k = 3;
  EXPECT_EQ(sol.minimumIncompatibility(nums, k), -1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {1};
  int k = 1;
  EXPECT_EQ(sol.minimumIncompatibility(nums, k), 0);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  int k = 3;
  EXPECT_EQ(sol.minimumIncompatibility(nums, k), 0);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> nums = {2,8,2,9,2,8,2,9,6,8,6,8};
  int k = 6;
  EXPECT_EQ(sol.minimumIncompatibility(nums, k), 22);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> nums = {13,4,7,3,3,1,12,9,11,10,13,3,12,7};
  int k = 7;
  LOG(INFO) << "nums size: " << nums.size();
  EXPECT_EQ(sol.minimumIncompatibility(nums, k), 12);
}

