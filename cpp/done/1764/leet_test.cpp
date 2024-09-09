#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "leet.cpp"
#include <cassert>
#include <gtest/gtest.h>

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> groups = {{1, -1, -1}, {3, -2, 0}};
  vector<int> nums = {1, -1, 0, 1, -1, -1, 3, -2, 0};
  EXPECT_EQ(sol.canChoose(groups, nums), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> groups = {{10, -2}, {1, 2, 3, 4}};
  vector<int> nums = {1, 2, 3, 4, 10, -2};
  EXPECT_EQ(sol.canChoose(groups, nums), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> groups = {{1, 2, 3}, {3, 4}};
  vector<int> nums = {7, 7, 1, 2, 3, 4, 7, 7};
  EXPECT_EQ(sol.canChoose(groups, nums), false);
}

