#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};
  EXPECT_EQ(sol.hasValidPath(grid), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid = {{1, 2, 1}, {1, 2, 1}};
  EXPECT_EQ(sol.hasValidPath(grid), false);
}
TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid = {{1, 1, 2}};
  EXPECT_EQ(sol.hasValidPath(grid), false);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 3}};
  EXPECT_EQ(sol.hasValidPath(grid), true);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> grid = {{2}, {2}, {2}, {2}, {2}, {2}, {6}};
  EXPECT_EQ(sol.hasValidPath(grid), true);
}

TEST(kk, t6) {
  Solution sol;
  vector<vector<int>> grid = {{6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
                              {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5},
                              {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
                              {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5},
                              {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
                              {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5},
                              {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
                              {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5},
                              {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
                              {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5},
                              {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
                              {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5},
                              {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3},
                              {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5},
                              {6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3}};

  EXPECT_EQ(sol.hasValidPath(grid), true);
}

