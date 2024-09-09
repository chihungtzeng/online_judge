#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 5, 3, 6, 1, 12 };
  int original = 3;
  EXPECT_EQ(sol.findFinalValue(nums, original), 24);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 2, 7, 9 };
  int original = 4;
  EXPECT_EQ(sol.findFinalValue(nums, original), 4);
}

