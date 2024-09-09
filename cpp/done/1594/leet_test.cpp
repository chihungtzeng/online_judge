#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid = {{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}};
  EXPECT_EQ(sol.maxProductPath(grid), -1);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid = {{1, -2, 1}, {1, -2, 1}, {3, -4, 1}};
  EXPECT_EQ(sol.maxProductPath(grid), 8);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid = {{1, 3}, {0, -4}};
  EXPECT_EQ(sol.maxProductPath(grid), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> grid = {{1, 4, 4, 0}, {-2, 0, 0, 1}, {1, -1, 1, 1}};
  EXPECT_EQ(sol.maxProductPath(grid), 2);
}

