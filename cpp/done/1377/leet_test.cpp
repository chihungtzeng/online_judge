#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
  int t = 2, target = 4;
  EXPECT_TRUE(abs(sol.frogPosition(n, edges, t, target) -
                  0.16666666666666666) <= 0.00001);
}

TEST(kk, t2) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
  int t = 1, target = 7;
  EXPECT_TRUE(abs(sol.frogPosition(n, edges, t, target) - 0.3333333333333333) <=
              0.00001);
}

TEST(kk, t3) {
  Solution sol;
  int n = 7;
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
  int t = 20, target = 6;
  EXPECT_TRUE(abs(sol.frogPosition(n, edges, t, target) -
                  0.16666666666666666) <= 0.00001);
}

TEST(kk, t4) {
  Solution sol;
  int n = 8;
  vector<vector<int>> edges = {{2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}};
  int t = 7, target = 7;
  EXPECT_TRUE(abs(sol.frogPosition(n, edges, t, target) -
                  0) <= 0.00001);
}

