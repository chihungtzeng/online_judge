#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> inventory = {2, 5};
  int orders = 4;
  EXPECT_EQ(sol.maxProfit(inventory, orders), 14);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> inventory = {3, 5};
  int orders = 6;
  EXPECT_EQ(sol.maxProfit(inventory, orders), 19);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> inventory = {2, 8, 4, 10, 6};
  int orders = 20;
  EXPECT_EQ(sol.maxProfit(inventory, orders), 110);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> inventory = {1000000000};
  int orders = 1000000000;
  EXPECT_EQ(sol.maxProfit(inventory, orders), 21);
}
TEST(kk, t5) {
  Solution sol;

  vector<int> inventory = {497978859, 167261111, 483575207, 591815159};
  int orders = 836556809;

  EXPECT_EQ(sol.maxProfit(inventory, orders), 373219333);
}

