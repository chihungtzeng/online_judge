#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> expect{{1,6},{8,10},{15,18}};
  EXPECT_EQ(sol.merge(intervals), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> intervals = {{1,4},{4,5}};
  vector<vector<int>> expect{{1,5}};
  EXPECT_EQ(sol.merge(intervals), expect);
}

