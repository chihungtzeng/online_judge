#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> hours = {9,9,6,0,6,6,9};
  EXPECT_EQ(sol.longestWPI(hours), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> hours = {1, 3,6,0,6,6,9};
  EXPECT_EQ(sol.longestWPI(hours), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> hours = {1, 3,6,0,6,6,8};
  EXPECT_EQ(sol.longestWPI(hours), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> hours = {6,9,9};
  EXPECT_EQ(sol.longestWPI(hours), 3);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> hours = {19,9,9};
  EXPECT_EQ(sol.longestWPI(hours), 3);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> hours = {9,6,9};
  EXPECT_EQ(sol.longestWPI(hours), 3);
}

