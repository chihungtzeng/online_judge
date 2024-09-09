#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 1, 2, 1, 1};
  int k = 3;
  EXPECT_EQ(sol.numberOfSubarrays(nums, k), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2, 4, 6};
  int k = 1;
  EXPECT_EQ(sol.numberOfSubarrays(nums, k), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
  int k = 2;
  EXPECT_EQ(sol.numberOfSubarrays(nums, k), 16);
}

