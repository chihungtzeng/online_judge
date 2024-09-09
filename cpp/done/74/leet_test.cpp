#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
  int target = 3;
  EXPECT_EQ(sol.searchMatrix(matrix, target), true);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
  int target = 13;
  EXPECT_EQ(sol.searchMatrix(matrix, target), false);
}

