#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> matrix = {{5, 2}, {1, 6}};
  int k = 1;
  EXPECT_EQ(sol.kthLargestValue(matrix, k), 7);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> matrix = {{5, 2}, {1, 6}};
  int k = 2;
  EXPECT_EQ(sol.kthLargestValue(matrix, k), 5);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> matrix = {{5, 2}, {1, 6}};
  int k = 3;
  EXPECT_EQ(sol.kthLargestValue(matrix, k), 4);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> matrix = {{5, 2}, {1, 6}};
  int k = 4;
  EXPECT_EQ(sol.kthLargestValue(matrix, k), 0);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> matrix = {
      {3, 1, 4, 1, 5}, {2, 7, 1, 8, 2}, {1, 5, 9, 2, 6}, {4, 1, 3, 99, 7}};
  int k = 4;
  EXPECT_EQ(sol.kthLargestValue(matrix, k), 12);
}

