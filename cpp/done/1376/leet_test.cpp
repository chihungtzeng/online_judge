#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 1, headID = 0;
  vector<int> manager = {-1}, informTime = {0};
  EXPECT_EQ(sol.numOfMinutes(n, headID, manager, informTime), 0);
}

TEST(kk, t2) {
  Solution sol;
  int n = 6, headID = 2;
  vector<int> manager = {2, 2, -1, 2, 2, 2}, informTime = {0, 0, 1, 0, 0, 0};
  EXPECT_EQ(sol.numOfMinutes(n, headID, manager, informTime), 1);
}

TEST(kk, t3) {
  Solution sol;
  int n = 7, headID = 6;
  vector<int> manager = {1, 2, 3, 4, 5, 6, -1},
              informTime = {0, 6, 5, 4, 3, 2, 1};
  EXPECT_EQ(sol.numOfMinutes(n, headID, manager, informTime), 21);
}

TEST(kk, t4) {
  Solution sol;
  int n = 15, headID = 0;
  vector<int> manager = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6},
              informTime = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_EQ(sol.numOfMinutes(n, headID, manager, informTime), 3);
}

TEST(kk, t5) {
  Solution sol;
  int n = 4, headID = 2;
  vector<int> manager = {3, 3, -1, 2}, informTime = {0, 0, 162, 914};
  EXPECT_EQ(sol.numOfMinutes(n, headID, manager, informTime), 1076);
}

