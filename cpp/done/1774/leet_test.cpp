#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> baseCosts = {1, 7}, toppingCosts = {3, 4};
  int target = 10;
  EXPECT_EQ(sol.closestCost(baseCosts, toppingCosts, target), 10);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> baseCosts = {2, 3}, toppingCosts = {4, 5, 100};
  int target = 18;
  EXPECT_EQ(sol.closestCost(baseCosts, toppingCosts, target), 17);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> baseCosts = {3, 10}, toppingCosts = {2, 5};
  int target = 9;
  EXPECT_EQ(sol.closestCost(baseCosts, toppingCosts, target), 8);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> baseCosts = {10}, toppingCosts = {1};
  int target = 1;
  EXPECT_EQ(sol.closestCost(baseCosts, toppingCosts, target), 10);
}

