#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
  int bricks = 5, ladders = 1;
  EXPECT_EQ(sol.furthestBuilding(heights, bricks, ladders), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> heights = {1, 61, 62, 63, 64, 65};
  int bricks = 60, ladders = 1;
  EXPECT_EQ(sol.furthestBuilding(heights, bricks, ladders), 5);
}

