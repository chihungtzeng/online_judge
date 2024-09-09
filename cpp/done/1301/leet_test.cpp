#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> board = {"E23", "2X2", "12S"};
  vector<int> expect{7, 1};
  EXPECT_EQ(sol.pathsWithMaxScore(board), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> board = {"E12", "1X1", "21S"};
  vector<int> expect{4, 2};
  EXPECT_EQ(sol.pathsWithMaxScore(board), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> board = {"E11", "XXX", "11S"};
  vector<int> expect{0, 0};
  EXPECT_EQ(sol.pathsWithMaxScore(board), expect);
}

