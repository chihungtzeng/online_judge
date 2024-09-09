#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 3;
  vector<vector<int>> edgeList = {{0, 1, 2}, {1, 2, 4}, {2, 0, 8}, {1, 0, 16}},
                      queries = {{0, 1, 2}, {0, 2, 5}};
  vector<bool> expect{false, true};
  EXPECT_EQ(sol.distanceLimitedPathsExist(n, edgeList, queries), expect);
}

TEST(kk, t2) {
  Solution sol;
  int n = 5;
  vector<vector<int>> edgeList = {{0, 1, 10}, {1, 2, 5}, {2, 3, 9}, {3, 4, 13}},
                      queries = {{0, 4, 14}, {1, 4, 13}};
  vector<bool> expect{true, false};
  EXPECT_EQ(sol.distanceLimitedPathsExist(n, edgeList, queries), expect);
}

