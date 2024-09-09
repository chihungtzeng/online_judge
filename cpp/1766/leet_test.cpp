#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {2, 3, 3, 2};
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}};
  vector<int> expect{-1, 0, 0, 1};
  EXPECT_EQ(sol.getCoprimes(nums, edges), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {5, 6, 10, 2, 3, 6, 15};
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
  vector<int> expect{-1, 0, -1, 0, 0, 0, -1};
  EXPECT_EQ(sol.getCoprimes(nums, edges), expect);
}

