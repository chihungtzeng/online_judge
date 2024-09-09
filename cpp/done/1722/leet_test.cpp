#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> source = {1, 2, 3, 4}, target = {2, 1, 4, 5};
  vector<vector<int>> allowedSwaps = {{0, 1}, {2, 3}};
  EXPECT_EQ(sol.minimumHammingDistance(source, target, allowedSwaps), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> source = {1, 2, 3, 4}, target = {1, 3, 2, 4};
  vector<vector<int>> allowedSwaps = {};
  EXPECT_EQ(sol.minimumHammingDistance(source, target, allowedSwaps), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> source = {5, 1, 2, 4, 3}, target = {1, 5, 4, 2, 3};
  vector<vector<int>> allowedSwaps = {{0, 4}, {4, 2}, {1, 3}, {1, 4}};
  EXPECT_EQ(sol.minimumHammingDistance(source, target, allowedSwaps), 0);
}

