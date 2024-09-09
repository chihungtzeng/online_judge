#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 6;
  vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
  EXPECT_EQ(sol.minReorder(n, connections), 3);
}

TEST(kk, t2) {
  Solution sol;
  int n = 5;
  vector<vector<int>> connections = {{1,0},{1,2},{3,2},{3,4}};
  EXPECT_EQ(sol.minReorder(n, connections), 2);
}

TEST(kk, t3) {
  Solution sol;
  int n = 3;
  vector<vector<int>> connections = {{1,0},{2,0}};
  EXPECT_EQ(sol.minReorder(n, connections), 0);
}

