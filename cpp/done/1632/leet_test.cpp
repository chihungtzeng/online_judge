#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> matrix = {{1, 2}, {3, 4}};
  vector<vector<int>> expect{{1, 2}, {2, 3}};
  EXPECT_EQ(sol.matrixRankTransform(matrix), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> matrix = {{7, 7}, {7, 7}};
  vector<vector<int>> expect{{1, 1}, {1, 1}};
  EXPECT_EQ(sol.matrixRankTransform(matrix), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> matrix = {
      {20, -21, 14}, {-19, 4, 19}, {22, -47, 24}, {-19, 4, 19}};
  vector<vector<int>> expect{{4, 2, 3}, {1, 3, 4}, {5, 1, 6}, {1, 3, 4}};

  EXPECT_EQ(sol.matrixRankTransform(matrix), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> matrix = {{7, 3, 6}, {1, 4, 5}, {9, 8, 2}};
  vector<vector<int>> expect{{5, 1, 4}, {1, 2, 3}, {6, 3, 1}};
  EXPECT_EQ(sol.matrixRankTransform(matrix), expect);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> matrix{{-37, -50, -3, 44},
                             {-37, 46, 13, -32},
                             {47, -42, -3, -40},
                             {-17, -22, -39, 24}};

  vector<vector<int>> expect{
      {2, 1, 4, 6}, {2, 6, 5, 4}, {5, 2, 4, 3}, {4, 3, 1, 5}};

  EXPECT_EQ(sol.matrixRankTransform(matrix), expect);
}

TEST(kk, t6) {
  Solution sol;
  vector<vector<int>> matrix{{-32, 15, 38, 17, -44, 43, 42, -47, -44, -41},
                             {34, -43, -24, 7, -10, -43, 36, -5, -22, 37},
                             {4, -13, -38, 49, 16, -21, 30, 13, -20, 47},
                             {2, -35, 32, 11, 26, -31, 40, 31, -46, -7},
                             {4, 19, 18, -27, 16, 43, -10, -11, 44, 39},
                             {18, 9, 48, -29, 30, 5, 8, -13, -42, -43},
                             {48, 47, 30, 29, 24, -29, 22, -31, 12, -37},
                             {38, -23, 44, -13, -46, 37, -12, 31, 14, -31},
                             {-28, 23, -50, -23, 12, 23, 18, -11, -44, 31},
                             {-10, 37, 16, 11, -18, 17, 40, -41, 26, -31}};

  vector<vector<int>> expect{{4, 12, 17, 13, 2, 19, 18, 1, 2, 3},
                             {13, 1, 3, 9, 7, 1, 14, 8, 4, 17},
                             {10, 9, 2, 20, 12, 7, 13, 11, 8, 19},
                             {8, 2, 16, 10, 14, 3, 17, 15, 1, 6},
                             {10, 14, 13, 5, 12, 19, 9, 7, 20, 18},
                             {12, 11, 19, 4, 15, 8, 10, 6, 3, 1},
                             {18, 17, 15, 14, 13, 6, 12, 5, 9, 4},
                             {17, 6, 18, 7, 1, 16, 8, 15, 10, 5},
                             {5, 15, 1, 6, 8, 15, 11, 7, 2, 16},
                             {7, 16, 11, 10, 6, 12, 17, 2, 13, 5}};
  // rows = 10, cols = 10
  auto actual = sol.matrixRankTransform(matrix);
  int rows = matrix.size(), cols = matrix[0].size();
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (actual[r][c] != expect[r][c]) {
        LOG(INFO) << "val " << matrix[r][c] << " differ at (" << r << ", " << c
                  << ")";
      }
    }
  }
  //  0 1 2   3  4  5  6  7 8  9  10 11 12 13 14 15 16 17 18 19
  // ----------------------------------------------------------
  // 13 9 12 10 14 12 12 10 11 12 12 14 13 13 12 12 12 11 10 6  ranks before
  // 13 9 12 10 14 12 12 10 11 12 12 14 13 13 12 12 12 11 10 6  
  EXPECT_EQ(actual, expect);
}

