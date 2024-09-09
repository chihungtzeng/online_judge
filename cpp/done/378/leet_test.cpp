#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> org_matrix{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};

  auto matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 1), 1);
  matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 2), 5);
  matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 3), 9);
  matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 4), 10);
  matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 5), 11);
  matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 6), 12);
  matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 7), 13);
  matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 8), 13);
  matrix = org_matrix;
  EXPECT_EQ(sol.kthSmallest(matrix, 9), 15);
}

