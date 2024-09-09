#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> expect{1, 2, 4, 7, 5, 3, 6, 8, 9};
  EXPECT_EQ(sol.findDiagonalOrder(matrix), expect);

  vector<vector<int>> matrix2{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
  vector<int> expect2{1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(sol.findDiagonalOrder(matrix2), expect2);

  vector<vector<int>> matrix3{{1}, {2}, {3}};
  vector<int> expect3{1, 2, 3};
  EXPECT_EQ(sol.findDiagonalOrder(matrix3), expect3);
}

