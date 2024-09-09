#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
  EXPECT_EQ(sol.numSubmat(mat), 13);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> mat = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
  EXPECT_EQ(sol.numSubmat(mat), 24);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> mat = {{1, 1, 1, 1, 1, 1}};
  EXPECT_EQ(sol.numSubmat(mat), 21);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> mat = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
  EXPECT_EQ(sol.numSubmat(mat), 5);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> mat = {
      {0, 1, 1, 0}, {0, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 0}};
  EXPECT_EQ(sol.numSubmat(mat), 28);
}

TEST(kk, t6) {
  Solution sol;
  vector<vector<int>> mat = {{0,0,0},{0,0,0},{0,1,1},{1,1,0},{0,1,1}};
  EXPECT_EQ(sol.numSubmat(mat), 12);
}

