#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> input{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
  vector<vector<int>> expect{{5,0}, {7,0}, {5,2}, {6,1}, {4,4}, {7,1}};

  EXPECT_EQ(sol.reconstructQueue(input), expect);
}

