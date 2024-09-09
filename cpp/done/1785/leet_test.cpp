#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1, -1, 1};
  int limit = 3, goal = -4;
  EXPECT_EQ(sol.minElements(nums, limit, goal), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1, -10, 9, 1};
  int limit = 100, goal = 0;
  EXPECT_EQ(sol.minElements(nums, limit, goal), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1, -10, 9, 1, 11, -17, -9, -2, 4, 2};
  int limit = 97, goal = 100000000;
  EXPECT_EQ(sol.minElements(nums, limit, goal), 1030928);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums;
  int limit = 1000000, goal = -1000000000;
  for (int i=0; i<10000; i++){
    nums.push_back(1000000);
  }
  EXPECT_EQ(sol.minElements(nums, limit, goal), 11000);
}

