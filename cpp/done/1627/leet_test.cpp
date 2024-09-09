#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 6, threshold = 2;
  vector<vector<int>> queries = {{1, 4}, {2, 5}, {3, 6}};
  vector<bool> expect{false, false, true};
  EXPECT_EQ(sol.areConnected(n, threshold, queries), expect);
}

TEST(kk, t2) {
  Solution sol;
  int n = 6, threshold = 0;
  vector<vector<int>> queries = {{4, 5}, {3, 4}, {3, 2}, {2, 6}, {1, 3}};
  vector<bool> expect{true, true, true, true, true};
  EXPECT_EQ(sol.areConnected(n, threshold, queries), expect);
}

TEST(kk, t3) {
  Solution sol;
  int n = 5, threshold = 1;
  vector<vector<int>> queries = {{4, 5}, {4, 5}, {3, 2}, {2, 3}, {3, 4}};
  vector<bool> expect{false, false, false, false, false};
  EXPECT_EQ(sol.areConnected(n, threshold, queries), expect);
}

