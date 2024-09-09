#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<vector<int>> requests = {{1, 3}, {0, 1}};
  EXPECT_EQ(sol.maxSumRangeQuery(nums, requests), 19);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  vector<vector<int>> requests = {{0, 1}};
  EXPECT_EQ(sol.maxSumRangeQuery(nums, requests), 11);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 10};
  vector<vector<int>> requests = {{0, 2}, {1, 3}, {1, 1}};
  EXPECT_EQ(sol.maxSumRangeQuery(nums, requests), 47);
}

