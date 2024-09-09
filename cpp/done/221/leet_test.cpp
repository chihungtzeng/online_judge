#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                              {'1', '0', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '0', '0', '1', '0'}};

  EXPECT_EQ(sol.maximalSquare(matrix), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<char>> matrix;

  EXPECT_EQ(sol.maximalSquare(matrix), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<char>> matrix{{'1', '0', '1', '1', '1'}};

  EXPECT_EQ(sol.maximalSquare(matrix), 1);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                              {'1', '0', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '0', '1', '1', '1'}};

  EXPECT_EQ(sol.maximalSquare(matrix), 9);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<char>> matrix{{'0', '0', '0', '1'},
                              {'1', '1', '0', '1'},
                              {'1', '1', '1', '1'},
                              {'0', '1', '1', '1'},
                              {'0', '1', '1', '1'}};
  EXPECT_EQ(sol.maximalSquare(matrix), 9);
}

