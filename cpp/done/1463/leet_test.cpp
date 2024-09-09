#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
  EXPECT_EQ(sol.cherryPickup(grid), 24);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid{{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
  EXPECT_EQ(sol.cherryPickup(grid), 28);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid{{1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3}};
  EXPECT_EQ(sol.cherryPickup(grid), 22);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> grid{{1,1},{1,1}};
  EXPECT_EQ(sol.cherryPickup(grid), 4);
}


