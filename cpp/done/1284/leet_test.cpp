#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> mat = {{0, 0}, {0, 1}};
  EXPECT_EQ(sol.minFlips(mat), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> mat = {{0}};
  EXPECT_EQ(sol.minFlips(mat), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> mat = {{1, 1, 1}, {1, 0, 1}, {0, 0, 0}};
  EXPECT_EQ(sol.minFlips(mat), 6);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> mat = {{1, 0, 0}, {1, 0, 0}};
  EXPECT_EQ(sol.minFlips(mat), -1);
}

