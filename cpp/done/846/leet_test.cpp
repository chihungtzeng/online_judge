#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> hand = { 1, 2, 3, 6, 2, 3, 4, 7, 8 };
  int W = 3;
  EXPECT_EQ(sol.isNStraightHand(hand, W), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> hand = { 1, 2, 3, 4, 5 };
  int W = 4;
  EXPECT_EQ(sol.isNStraightHand(hand, W), false);
}

