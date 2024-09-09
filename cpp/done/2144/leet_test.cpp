#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> cost = {1,2,3};
  EXPECT_EQ(sol.minimumCost(cost), 5);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> cost = {6,5,7,9,2,2};
  EXPECT_EQ(sol.minimumCost(cost), 23);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> cost = {5,5};
  EXPECT_EQ(sol.minimumCost(cost), 10);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> cost = {3,2, 4, 3};
  EXPECT_EQ(sol.minimumCost(cost), 9);
}

