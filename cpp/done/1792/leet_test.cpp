#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> classes = { { 1, 2 }, { 3, 5 }, { 2, 2 } };
  int extraStudents = 2;
  auto res = sol.maxAverageRatio(classes, extraStudents);
  EXPECT_TRUE(abs(res - 0.78333) <= 0.00001);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> classes = { { 2, 4 }, { 3, 9 }, { 4, 5 }, { 2, 10 } };
  int extraStudents = 4;
  auto res = sol.maxAverageRatio(classes, extraStudents);
  EXPECT_TRUE(abs(res - 0.53485) <= 0.00001);
}

