#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> edges{{1,2}, {1,3}, {2,3}};
  vector<int> expect{2,3};

  EXPECT_EQ(sol.findRedundantConnection(edges), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> edges{{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
  vector<int> expect{1,4};

  EXPECT_EQ(sol.findRedundantConnection(edges), expect);
}

