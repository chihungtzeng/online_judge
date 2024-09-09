#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int h = 5, w = 4;
  vector<int> horizontalCuts = {1, 2, 4}, verticalCuts = {1, 3};
  EXPECT_EQ(sol.maxArea(h, w, horizontalCuts, verticalCuts), 4);
}

TEST(kk, t2) {
  Solution sol;
  int h = 5, w = 4;
  vector<int> horizontalCuts = {3, 1}, verticalCuts = {1};
  EXPECT_EQ(sol.maxArea(h, w, horizontalCuts, verticalCuts), 6);
}

TEST(kk, t3) {
  Solution sol;
  int h = 5, w = 4;
  vector<int> horizontalCuts = {3}, verticalCuts = {3};
  EXPECT_EQ(sol.maxArea(h, w, horizontalCuts, verticalCuts), 9);
}

