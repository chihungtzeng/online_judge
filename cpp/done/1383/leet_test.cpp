#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 6;
  vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};
  int k = 2;
  EXPECT_EQ(sol.maxPerformance(n, speed, efficiency, k), 60);
}

TEST(kk, t2) {
  Solution sol;
  int n = 6;
  vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};
  int k = 3;
  EXPECT_EQ(sol.maxPerformance(n, speed, efficiency, k), 68);
}

TEST(kk, t3) {
  Solution sol;
  int n = 6;
  vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};
  int k = 4;
  EXPECT_EQ(sol.maxPerformance(n, speed, efficiency, k), 72);
}

TEST(kk, t4) {
  Solution sol;
  int n = 3;
  vector<int> speed = {2, 8, 2}, efficiency = {2,7,1};
  int k = 2;
  EXPECT_EQ(sol.maxPerformance(n, speed, efficiency, k), 56);
}

