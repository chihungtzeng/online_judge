#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> dist = {1,3,2}; double hour = 6;
  EXPECT_EQ(sol.minSpeedOnTime(dist, hour), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> dist = {1,3,2}; double hour = 2.7;
  EXPECT_EQ(sol.minSpeedOnTime(dist, hour), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> dist = {1,3,2}; double hour = 1.9;
  EXPECT_EQ(sol.minSpeedOnTime(dist, hour), -1);
}

