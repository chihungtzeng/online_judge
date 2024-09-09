#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
vector<vector<int>> rooms = {{1},{2},{3},{}};
  EXPECT_EQ(sol.canVisitAllRooms(rooms), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
  EXPECT_EQ(sol.canVisitAllRooms(rooms), false);
}

