#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> statements = {{2,1,2},{1,2,2},{2,0,2}};
  EXPECT_EQ(sol.maximumGood(statements), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> statements = {{2,0},{0,2}};
  EXPECT_EQ(sol.maximumGood(statements), 1);
}

