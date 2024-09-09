#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> matrix = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
  EXPECT_EQ(sol.largestSubmatrix(matrix), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> matrix = {{1, 0, 1, 0, 1}};
  EXPECT_EQ(sol.largestSubmatrix(matrix), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> matrix = {{1, 1, 0}, {1, 0, 1}};
  EXPECT_EQ(sol.largestSubmatrix(matrix), 2);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> matrix = {{0, 0}, {0, 0}};
  EXPECT_EQ(sol.largestSubmatrix(matrix), 0);
}

