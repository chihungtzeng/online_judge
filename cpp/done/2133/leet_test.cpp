#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> matrix = {{1,2,3},{3,1,2},{2,3,1}};
  EXPECT_EQ(sol.checkValid(matrix), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> matrix = {{1,1,1},{1,2,3},{1,2,3}};
  EXPECT_EQ(sol.checkValid(matrix), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> matrix = {{1}};
  EXPECT_EQ(sol.checkValid(matrix), true);
}

