#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
  EXPECT_EQ(sol.getMaximumGold(grid), 24);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
  EXPECT_EQ(sol.getMaximumGold(grid), 28);
}

