#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> graph{{1,3}, {0,2}, {1,3}, {0,2}};

  EXPECT_EQ(sol.isBipartite(graph), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> graph{{1,2,3}, {0,2}, {0,1,3}, {0,2}};

  EXPECT_EQ(sol.isBipartite(graph), false);
}

