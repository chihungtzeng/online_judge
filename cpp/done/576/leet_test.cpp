#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
  EXPECT_EQ(sol.findPaths(m, n, maxMove, startRow, startColumn), 6);
}

TEST(kk, t2)
{
  Solution sol;
  int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
  EXPECT_EQ(sol.findPaths(m, n, maxMove, startRow, startColumn), 12);
}

TEST(kk, t3)
{
  Solution sol;
  int m = 1, n = 3, maxMove = 0, startRow = 0, startColumn = 1;
  EXPECT_EQ(sol.findPaths(m, n, maxMove, startRow, startColumn), 0);
}

TEST(kk, t4)
{
  Solution sol;
  int m = 50, n = 50, maxMove = 50, startRow = 25, startColumn = 25;
  EXPECT_EQ(sol.findPaths(m, n, maxMove, startRow, startColumn), 276775132);
}

