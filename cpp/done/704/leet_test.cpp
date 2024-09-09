#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{-1,0,3,5,9,12};
  int target = 9;

  EXPECT_EQ(sol.search(nums, target), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{-1,0,3,5,9,12};
  int target = 2;

  EXPECT_EQ(sol.search(nums, target), -1);
}

