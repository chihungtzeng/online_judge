#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> grid = { { 1, 2 }, { 3, 4 } };
  EXPECT_EQ(sol.surfaceArea(grid), 34);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> grid = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
  EXPECT_EQ(sol.surfaceArea(grid), 32);
}

TEST(kk, t3)
{
  Solution sol;
  vector<vector<int>> grid = { { 2, 2, 2 }, { 2, 1, 2 }, { 2, 2, 2 } };
  EXPECT_EQ(sol.surfaceArea(grid), 46);
}

