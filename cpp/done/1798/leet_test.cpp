#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> coins = {1, 3};
  EXPECT_EQ(sol.getMaximumConsecutive(coins), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> coins = {1, 1, 1, 4};
  EXPECT_EQ(sol.getMaximumConsecutive(coins), 8);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> coins = {1, 4, 10, 3, 1};
  EXPECT_EQ(sol.getMaximumConsecutive(coins), 20);
}

TEST(kk, t4) {
  Solution sol;

  vector<int> coins = {3, 1, 4, 1, 5, 9, 2, 6, 2, 7, 1, 8, 2, 8};
  EXPECT_EQ(sol.getMaximumConsecutive(coins), 60);
}

