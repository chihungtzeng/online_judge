#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> positions = { { 1, 2 }, { 2, 3 }, { 6, 1 } };
  vector<int> expect{ 2, 5, 5 };
  EXPECT_EQ(sol.fallingSquares(positions), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> positions = { { 100, 100 }, { 200, 100 } };

  vector<int> expect{ 100, 100 };
  EXPECT_EQ(sol.fallingSquares(positions), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<vector<int>> positions = { { 1, 2 }, { 2, 3 }, { 6, 1 }, { 3, 2 }, { 2, 3 }, { 100, 100 } };
  // [ [ 1, 2 ], [ 2, 3 ], [ 6, 1 ] , [3, 2], [2, 3], [100, 100]]
  vector<int> expect{ 2, 5, 5, 7, 10, 100 };
  EXPECT_EQ(sol.fallingSquares(positions), expect);
}

TEST(kk, t4)
{
  Solution sol;
  vector<vector<int>> positions = {{2,5},{2,7},{1,10},{1,10},{2,6}};
  vector<int> expect{5,12,22,32,38};

  EXPECT_EQ(sol.fallingSquares(positions), expect);
}

