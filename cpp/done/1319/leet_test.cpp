#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 4;
  vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
  EXPECT_EQ(sol.makeConnected(n, connections), 1);
}

TEST(kk, t2) {
  Solution sol;
  int n = 6;
  vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  EXPECT_EQ(sol.makeConnected(n, connections), 2);
}

TEST(kk, t3) {
  Solution sol;
  int n = 6;
  vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
  EXPECT_EQ(sol.makeConnected(n, connections), -1);
}

TEST(kk, t4) {
  Solution sol;
  int n = 5;
  vector<vector<int>> connections = {{0, 1}, {0, 2}, {3, 4}, {2, 3}};
  EXPECT_EQ(sol.makeConnected(n, connections), 0);
}

