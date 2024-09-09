#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 5;
  vector<int> ranges = {3, 4, 1, 1, 0, 0};
  EXPECT_EQ(sol.minTaps(n, ranges), 1);
}

TEST(kk, t2) {
  Solution sol;
  int n = 3;
  vector<int> ranges = {0, 0, 0, 0};
  EXPECT_EQ(sol.minTaps(n, ranges), -1);
}

TEST(kk, t3) {
  Solution sol;
  int n = 7;
  vector<int> ranges = {1, 2, 1, 0, 2, 1, 0, 1};
  EXPECT_EQ(sol.minTaps(n, ranges), 3);
}

TEST(kk, t4) {
  Solution sol;
  int n = 8;
  vector<int> ranges = {4, 0, 0, 0, 0, 0, 0, 0, 4};
  EXPECT_EQ(sol.minTaps(n, ranges), 2);
}

TEST(kk, t5) {
  Solution sol;
  int n = 8;
  vector<int> ranges = {4, 0, 0, 0, 4, 0, 0, 0, 4};
  EXPECT_EQ(sol.minTaps(n, ranges), 1);
}

TEST(kk, t6) {
  Solution sol;
  int n = 9;
  vector<int> ranges = {0,5,0,3,3,3,1,4,0,4};
  EXPECT_EQ(sol.minTaps(n, ranges), 2);
}

