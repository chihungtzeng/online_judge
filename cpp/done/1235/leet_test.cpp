#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> startTime = {1, 2, 3, 3}, endTime = {3, 4, 5, 6},
              profit = {50, 10, 40, 70};
  EXPECT_EQ(sol.jobScheduling(startTime, endTime, profit), 120);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> startTime = {1, 2, 3, 4, 6}, endTime = {3, 5, 10, 6, 9},
              profit = {20, 20, 100, 70, 60};
  EXPECT_EQ(sol.jobScheduling(startTime, endTime, profit), 150);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> startTime = {1, 1, 1}, endTime = {2, 3, 4}, profit = {5, 6, 4};
  EXPECT_EQ(sol.jobScheduling(startTime, endTime, profit), 6);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> startTime = {4, 2, 4, 8, 2};
  vector<int> endTime = {5, 5, 5, 10, 8};
  vector<int> profit = {1, 2, 8, 10, 4};
  EXPECT_EQ(sol.jobScheduling(startTime, endTime, profit), 18);
}

