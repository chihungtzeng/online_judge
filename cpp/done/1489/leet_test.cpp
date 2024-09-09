#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 5;
  vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2},
                               {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};
  vector<vector<int>> expect{{0, 1}, {2, 3, 4, 5}};
  EXPECT_EQ(sol.findCriticalAndPseudoCriticalEdges(n, edges), expect);
}

TEST(kk, t2) {
  Solution sol;
  int n = 4;
  vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}};
  vector<vector<int>> expect{{}, {0, 1, 2, 3}};
  EXPECT_EQ(sol.findCriticalAndPseudoCriticalEdges(n, edges), expect);
}

TEST(kk, t3) {
  Solution sol;
  int n = 6;
  vector<vector<int>> edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
  vector<vector<int>> expect{{3},{0,1,2,4,5,6}};
  EXPECT_EQ(sol.findCriticalAndPseudoCriticalEdges(n, edges), expect);
}

