#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> orders = {{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
  EXPECT_EQ(sol.getNumberOfBacklogOrders(orders), 6);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> orders = {{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}};
  EXPECT_EQ(sol.getNumberOfBacklogOrders(orders), 999999984);
}

