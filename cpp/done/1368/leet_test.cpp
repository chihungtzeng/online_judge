#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid = {
      {1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
  EXPECT_EQ(sol.minCost(grid), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid = {{1, 1, 3}, {3, 2, 2}, {1, 1, 4}};
  EXPECT_EQ(sol.minCost(grid), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid = {{1, 2}, {4, 3}};
  EXPECT_EQ(sol.minCost(grid), 1);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> grid = {{2, 2, 2}, {2, 2, 2}};
  EXPECT_EQ(sol.minCost(grid), 3);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> grid = {{4}};
  EXPECT_EQ(sol.minCost(grid), 0);
}

