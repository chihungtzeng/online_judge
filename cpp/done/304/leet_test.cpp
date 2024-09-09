#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  vector<vector<int>> matrix =
  { {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5} };
  NumMatrix sol(matrix);

  EXPECT_EQ(sol.sumRegion(2, 1, 4, 3), 8);
  EXPECT_EQ(sol.sumRegion(1,1,2,2), 11);
  EXPECT_EQ(sol.sumRegion(1,2,2,4), 12);
  EXPECT_EQ(sol.sumRegion(0,0,3,2), 26);
  EXPECT_EQ(sol.sumRegion(1, 0, 4, 2), 26);
  EXPECT_EQ(sol.sumRegion(0, 1, 4, 2), 16);
}

TEST(kk, t2) {
  vector<vector<int>> matrix = { {3}};
  NumMatrix sol(matrix);

  EXPECT_EQ(sol.sumRegion(0,0,0,0), 3);
}

TEST(kk, t3) {
  vector<vector<int>> matrix = { {3,1,4,1,5}};
  NumMatrix sol(matrix);

  EXPECT_EQ(sol.sumRegion(0,1,0,4), 11);
}

