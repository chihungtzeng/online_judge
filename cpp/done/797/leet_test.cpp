#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> graph{{1,2},{3},{3},{}};
  vector<vector<int>> expect{{0,1,3},{0,2,3}};

  EXPECT_EQ(sol.allPathsSourceTarget(graph), expect);
}

