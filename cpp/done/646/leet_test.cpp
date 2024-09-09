#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> pairs{{1,2}, {2,3}, {3,4}};

  EXPECT_EQ(sol.findLongestChain(pairs), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> pairs{{1,10}, {2,3}, {4,6}};

  EXPECT_EQ(sol.findLongestChain(pairs), 2);
}

