#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
  vector<int> expect{2,4,5,6};

  EXPECT_EQ(sol.eventualSafeNodes(graph), expect);
}

