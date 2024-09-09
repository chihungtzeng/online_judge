#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid = {
      {7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}};
  EXPECT_EQ(sol.largestMagicSquare(grid), 3);
}

#if 1
TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid = {{5, 1, 3, 1}, {9, 3, 3, 1}, {1, 3, 3, 8}};
  EXPECT_EQ(sol.largestMagicSquare(grid), 2);
}
#endif
