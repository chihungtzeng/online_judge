#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;

  vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
  EXPECT_EQ(sol.maxArea(height), 49);
}

TEST(kk, t2)
{
  Solution sol;

  vector<int> height = { 1, 1 };
  EXPECT_EQ(sol.maxArea(height), 1);
}

TEST(kk, t3)
{
  Solution sol;

  vector<int> height = { 1, 2, 1 };
  EXPECT_EQ(sol.maxArea(height), 2);
}

