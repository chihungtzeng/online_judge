#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> board{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  vector<vector<int>> expect{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};

  sol.gameOfLife(board);
  EXPECT_EQ(board, expect);
}

