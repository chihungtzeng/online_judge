#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> matrix = { { 0, 1, 0 }, { 1, 1, 1 }, { 0, 1, 0 } };
  int target = 0;
  EXPECT_EQ(sol.numSubmatrixSumTarget(matrix, target), 4);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> matrix = { { 1, -1 }, { -1, 1 } };
  int target = 0;
  EXPECT_EQ(sol.numSubmatrixSumTarget(matrix, target), 5);
}

TEST(kk, t3)
{
  Solution sol;
  vector<vector<int>> matrix = {{904}};
  int target = 0;
  EXPECT_EQ(sol.numSubmatrixSumTarget(matrix, target), 0);
}

