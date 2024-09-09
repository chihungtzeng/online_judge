#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
  int capacity = 4;
  EXPECT_EQ(sol.carPooling(trips, capacity), false);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};
  int capacity = 5;
  EXPECT_EQ(sol.carPooling(trips, capacity), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> trips = {{2, 1, 5}, {3, 5, 7}};
  int capacity = 3;
  EXPECT_EQ(sol.carPooling(trips, capacity), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> trips = {{3, 2, 7}, {3, 7, 9}, {8, 3, 9}};
  int capacity = 11;
  EXPECT_EQ(sol.carPooling(trips, capacity), true);
}

