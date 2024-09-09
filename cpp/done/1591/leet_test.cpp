#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> targetGrid = {{1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1}};
  EXPECT_EQ(sol.isPrintable(targetGrid), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> targetGrid = {{1,1,1,1},{1,1,3,3},{1,1,3,4},{5,5,1,4}};
  EXPECT_EQ(sol.isPrintable(targetGrid), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> targetGrid = {{1,2,1},{2,1,2},{1,2,1}};
  EXPECT_EQ(sol.isPrintable(targetGrid), false);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> targetGrid = {{1,1,1},{3,1,3}};
  EXPECT_EQ(sol.isPrintable(targetGrid), false);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> targetGrid = {{6,2,2,5},{2,2,2,5},{2,2,2,5},{4,3,3,4}};
  EXPECT_EQ(sol.isPrintable(targetGrid), true);
}

