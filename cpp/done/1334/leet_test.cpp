#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 4;
  vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
  int distanceThreshold = 4;
  EXPECT_EQ(sol.findTheCity(n, edges, distanceThreshold), 3);
}

TEST(kk, t2) {
  Solution sol;
  int n = 5;
  vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3},
                               {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
  int distanceThreshold = 2;
  EXPECT_EQ(sol.findTheCity(n, edges, distanceThreshold), 0);
}

