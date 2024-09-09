#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 1, 4, 3, 7, 4, 5 };
  int k = 3;
  EXPECT_EQ(sol.maximumScore(nums, k), 15);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 5, 5, 4, 5, 4, 1, 1, 1 };
  int k = 0;
  EXPECT_EQ(sol.maximumScore(nums, k), 20);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 6569, 9667, 3148, 7698, 1622, 2194, 793, 9041, 1670, 1872 };
  int k = 5;
  EXPECT_EQ(sol.maximumScore(nums, k), 9732);
}

