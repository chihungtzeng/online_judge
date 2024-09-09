#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> adjacentPairs = {{2,1},{3,4},{3,2}};
  vector<int> expect{1,2,3,4};
  EXPECT_EQ(sol.restoreArray(adjacentPairs), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> adjacentPairs = {{4,-2},{1,4},{-3,1}};
  vector<int> expect{-2,4,1,-3};
  EXPECT_EQ(sol.restoreArray(adjacentPairs), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> adjacentPairs = {{100000,-100000}};
  vector<int> expect{100000,-100000};
  EXPECT_EQ(sol.restoreArray(adjacentPairs), expect);
}

