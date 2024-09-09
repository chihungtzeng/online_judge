#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 5, 6, 2, 7, 4 };
  EXPECT_EQ(sol.maxProductDifference(nums), 34);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 4, 2, 5, 9, 7, 4, 8 };
  EXPECT_EQ(sol.maxProductDifference(nums), 64);
}

