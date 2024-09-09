#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> stones = {5,3,1,4,2};
  EXPECT_EQ(sol.stoneGameVII(stones), 6);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> stones = {7,90,5,1,100,10,10,2};
  EXPECT_EQ(sol.stoneGameVII(stones), 122);
}

