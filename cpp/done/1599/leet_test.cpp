#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> customers{8, 3};
  int boardingCost = 5, runningCost = 6;
  EXPECT_EQ(sol.minOperationsMaxProfit(customers, boardingCost, runningCost),
            3);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> customers = {10, 9, 6};
  int boardingCost = 6, runningCost = 4;
  EXPECT_EQ(sol.minOperationsMaxProfit(customers, boardingCost, runningCost),
            7);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> customers = {3, 4, 0, 5, 1};
  int boardingCost = 1, runningCost = 92;
  EXPECT_EQ(sol.minOperationsMaxProfit(customers, boardingCost, runningCost),
            -1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> customers = {10, 10, 6, 4, 7};
  int boardingCost = 3, runningCost = 8;
  EXPECT_EQ(sol.minOperationsMaxProfit(customers, boardingCost, runningCost),
            9);
}

