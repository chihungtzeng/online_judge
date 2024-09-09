#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> edges{{1,2}, {1,3}, {2,3}};
  vector<int> expect{2,3};

  EXPECT_EQ(sol.findRedundantDirectedConnection(edges), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> edges{{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};
  vector<int> expect{4,1};

  EXPECT_EQ(sol.findRedundantDirectedConnection(edges), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> edges{{2,1},{3,1},{4,2},{1,4}};
  vector<int> expect{2,1};

  EXPECT_EQ(sol.findRedundantDirectedConnection(edges), expect);
}

