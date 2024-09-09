#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int m = 3, n = 3;
  vector<vector<int>> positions = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
  vector<int> expect{1, 1, 2, 3};
  EXPECT_EQ(sol.numIslands2(m, n, positions), expect);
}

TEST(kk, t2) {
  Solution sol;
  int m = 3, n = 3;
  vector<vector<int>> positions = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {1,1}};
  vector<int> expect{1, 1, 2, 3, 1};
  EXPECT_EQ(sol.numIslands2(m, n, positions), expect);
}

TEST(kk, t3) {
  Solution sol;
  int m = 3, n = 3;
  vector<vector<int>> positions = {{0,0},{0,1},{1,2},{1,2}};

  vector<int> expect{1,1,2,2};

  EXPECT_EQ(sol.numIslands2(m, n, positions), expect);
}

TEST(kk, t4) {
  Solution sol;
  int m = 8, n = 4;
  vector<vector<int>> positions = {{0,0},{7,1},{6,1},{3,3},{4,1}};


  vector<int> expect{1,2,2,3,4};

  EXPECT_EQ(sol.numIslands2(m, n, positions), expect);
}

