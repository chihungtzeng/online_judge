#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,0,0}};
  EXPECT_EQ(sol.minSwaps(grid), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
  EXPECT_EQ(sol.minSwaps(grid), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid = {{1,0,0},{1,1,0},{1,1,1}};
  EXPECT_EQ(sol.minSwaps(grid), 0);
}

