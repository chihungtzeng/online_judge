#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 3;
  vector<vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8},
                                       {2, 6}, {3, 1}, {3, 10}};
  EXPECT_EQ(sol.maxNumberOfFamilies(n, reservedSeats), 4);
}

TEST(kk, t2) {
  Solution sol;
  int n = 2;
  vector<vector<int>> reservedSeats = {{2, 1}, {1, 8}, {2, 6}};
  EXPECT_EQ(sol.maxNumberOfFamilies(n, reservedSeats), 2);
}

TEST(kk, t3) {
  Solution sol;
  int n = 4;
  vector<vector<int>> reservedSeats = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
  EXPECT_EQ(sol.maxNumberOfFamilies(n, reservedSeats), 4);
}

