#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 4;
  vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
  vector<vector<int>> expect{{1, 3}};
  EXPECT_EQ(sol.criticalConnections(n, connections), expect);
}

TEST(kk, t2) {
  Solution sol;
  int n = 14;
  vector<vector<int>> connections = {
      {0, 1},   {1, 2},   {2, 0},  {2, 4}, {4, 3}, {4, 5},  {5, 6},
      {6, 3},   {4, 6},   {5, 7},  {7, 8}, {4, 9}, {9, 10}, {10, 11},
      {11, 12}, {12, 13}, {13, 9}, {9, 11}

  };
  vector<vector<int>> expect{{2, 4}, {4, 9}, {5, 7}, {7, 8}};
  auto actual = sol.criticalConnections(n, connections);
  sort(actual.begin(), actual.end());

  EXPECT_EQ(actual, expect);
}

