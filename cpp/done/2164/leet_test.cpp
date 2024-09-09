#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<int> nums = { 4, 1, 2, 3 };
  vector<int> expect{ 2, 3, 4, 1 };
  EXPECT_EQ(sol.sortEvenOdd(nums), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<int> nums = { 2, 1 };
  vector<int> expect{ 2, 1 };
  EXPECT_EQ(sol.sortEvenOdd(nums), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<int> nums = { 2, 1, 1 };
  vector<int> expect{ 1, 1, 2 };
  EXPECT_EQ(sol.sortEvenOdd(nums), expect);
}

