#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid{
      {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
  EXPECT_EQ(sol.numDistinctIslands(grid), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid{
      {1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};

  EXPECT_EQ(sol.numDistinctIslands(grid), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid{
      {1, 1, 1}, {0, 1, 0}, {0, 0, 0}, {1, 1, 0}, {0, 1, 1}};

  EXPECT_EQ(sol.numDistinctIslands(grid), 2);
}

#if 0
TEST(kk, t) {
  Solution sol;

  EXPECT_EQ(sol.numDistinctIslands(grid), );
}
#endif
