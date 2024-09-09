#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> points{{0,0},{2,2},{3,10},{5,2},{7,0}};
  EXPECT_EQ(sol.minCostConnectPoints(points), 20);
}
TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> points {{3,12},{-2,5},{-4,1}};
  EXPECT_EQ(sol.minCostConnectPoints(points), 18);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> points{{0,0},{1,1},{1,0},{-1,1}};
  EXPECT_EQ(sol.minCostConnectPoints(points), 4);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> points{{-1000000,-1000000},{1000000,1000000}};
  EXPECT_EQ(sol.minCostConnectPoints(points), 4000000);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<int>> points{{0,0}};
  EXPECT_EQ(sol.minCostConnectPoints(points), 0);
}

