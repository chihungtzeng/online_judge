#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
  EXPECT_EQ(sol.maxDistance(grid), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,0}};
  EXPECT_EQ(sol.maxDistance(grid), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid = {{0,0,0},{0,0,0},{0,0,0}};
  EXPECT_EQ(sol.maxDistance(grid), -1);
}

