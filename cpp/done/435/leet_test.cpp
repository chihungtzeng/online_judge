#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> intervals{{1,2},{2,3},{3,4},{1,3}};

  EXPECT_EQ(sol.eraseOverlapIntervals(intervals), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> intervals{{1,2},{1,2},{1,2}};

  EXPECT_EQ(sol.eraseOverlapIntervals(intervals), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> intervals{{1,2},{2,3}};

  EXPECT_EQ(sol.eraseOverlapIntervals(intervals), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> intervals{{0,2},{1,3},{2,4},{3,5},{4,6}};

  EXPECT_EQ(sol.eraseOverlapIntervals(intervals), 2);
}

