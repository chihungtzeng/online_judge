#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {42, 11, 1, 97};
  EXPECT_EQ(sol.countNicePairs(nums), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {13, 10, 35, 24, 76};
  EXPECT_EQ(sol.countNicePairs(nums), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums;
  for(int i=0; i<10; i++){
    nums.push_back(0);
  }
  EXPECT_EQ(sol.countNicePairs(nums), 45);
}

