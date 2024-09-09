#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> grid = { { 1, 2, 0, 1 }, { 1, 3, 0, 1 }, { 0, 2, 5, 1 } };
  vector<int> pricing = { 2, 5 }, start = { 0, 0 };
  int k = 3;
  vector<vector<int>> expect{ { 0, 1 }, { 1, 1 }, { 2, 1 } };
  EXPECT_EQ(sol.highestRankedKItems(grid, pricing, start, k), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> grid = { { 1, 2, 0, 1 }, { 1, 3, 3, 1 }, { 0, 2, 5, 1 } };
  vector<int> pricing = { 2, 3 }, start = { 2, 3 };
  int k = 2;
  vector<vector<int>> expect{ { 2, 1 }, { 1, 2 } };
  EXPECT_EQ(sol.highestRankedKItems(grid, pricing, start, k), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<vector<int>> grid = { { 1, 1, 1 }, { 0, 0, 1 }, { 2, 3, 4 } };
  vector<int> pricing = { 2, 3 }, start = { 0, 0 };
  int k = 3;
  vector<vector<int>> expect{ { 2, 1 }, { 2, 0 } };
  EXPECT_EQ(sol.highestRankedKItems(grid, pricing, start, k), expect);
}

