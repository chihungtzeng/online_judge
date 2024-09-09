#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> nums{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> expect{1, 4, 2, 7, 5, 3, 8, 6, 9};
  EXPECT_EQ(sol.findDiagonalOrder(nums), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> nums{
      {1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
  vector<int> expect{1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16};
  EXPECT_EQ(sol.findDiagonalOrder(nums), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> nums{{1, 2, 3}, {4}, {5, 6, 7}, {8}, {9, 10, 11}};
  vector<int> expect{1, 4, 2, 5, 3, 8, 6, 9, 7, 10, 11};
  EXPECT_EQ(sol.findDiagonalOrder(nums), expect);
}
TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> nums{{1, 2, 3, 4, 5, 6}};
  vector<int> expect{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(sol.findDiagonalOrder(nums), expect);
}

