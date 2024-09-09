#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 5; vector<vector<int>> restrictions = {{2,1},{4,1}};
  EXPECT_EQ(sol.maxBuilding(n, restrictions), 2);
}

TEST(kk, t2) {
  Solution sol;
  int n = 6; vector<vector<int>> restrictions = {};
  EXPECT_EQ(sol.maxBuilding(n, restrictions), 5);
}

TEST(kk, t3) {
  Solution sol;
  int n = 10; vector<vector<int>> restrictions = {{5,3},{2,5},{7,4},{10,3}};
  EXPECT_EQ(sol.maxBuilding(n, restrictions), 5);
}


TEST(kk, t4) {
  Solution sol;
  int n = 10; 
  vector<vector<int>> restrictions = 
{{8,5},{9,0},{6,2},{4,0},{3,2},{10,0},{5,3},{7,3},{2,4}};
  EXPECT_EQ(sol.maxBuilding(n, restrictions), 2);
}


