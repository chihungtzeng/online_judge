#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 1, 2, 3, 4, 5, 6 };
  int numSlots = 3;
  EXPECT_EQ(sol.maximumANDSum(nums, numSlots), 9);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 1, 3, 10, 4, 7, 1 };
  int numSlots = 9;
  EXPECT_EQ(sol.maximumANDSum(nums, numSlots), 24);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 14, 7, 14, 6, 8, 1, 5, 15, 3, 6, 9, 11, 3, 13, 14, 14, 11, 2 };
  int numSlots = 9;
  EXPECT_EQ(sol.maximumANDSum(nums, numSlots), 90);
}

