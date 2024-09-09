#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> board = {{1,2,3},{4,0,5}};
  EXPECT_EQ(sol.slidingPuzzle(board), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> board = {{1,2,3},{5,4,0}};
  EXPECT_EQ(sol.slidingPuzzle(board), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> board = {{4,1,2},{5,0,3}};
  EXPECT_EQ(sol.slidingPuzzle(board), 5);
}

