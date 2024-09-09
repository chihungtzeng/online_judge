#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> isWater = {{0, 1}, {0, 0}};
  vector<vector<int>> expect{{1, 0}, {2, 1}};
  EXPECT_EQ(sol.highestPeak(isWater), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> isWater = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
  vector<vector<int>> expect{{1, 1, 0}, {0, 1, 1}, {1, 2, 2}};
  EXPECT_EQ(sol.highestPeak(isWater), expect);
}

