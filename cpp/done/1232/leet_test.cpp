#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
   vector<vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
  EXPECT_EQ(sol.checkStraightLine(coordinates), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> coordinates = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
  EXPECT_EQ(sol.checkStraightLine(coordinates), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> coordinates = {{2,4},{2,5},{2,8}};
  
  EXPECT_EQ(sol.checkStraightLine(coordinates), true);
}

TEST(kk, t4) {
  Solution sol;

  vector<vector<int>> coordinates = {{0,1},{1,3},{-4,-7},{5,11}};
  
  EXPECT_EQ(sol.checkStraightLine(coordinates), true);
}

