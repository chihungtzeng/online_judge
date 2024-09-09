#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 9, 12, 5, 10, 14, 3, 10 };
  int pivot = 10;
  vector<int> expect{ 9, 5, 3, 10, 10, 12, 14 };
  EXPECT_EQ(sol.pivotArray(nums, pivot), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { -3, 4, 3, 2 };
  int pivot = 2;
  vector<int> expect{ -3, 2, 4, 3 };
  EXPECT_EQ(sol.pivotArray(nums, pivot), expect);
}

