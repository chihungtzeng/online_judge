#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{10, 2, -10, 5, 20};
  EXPECT_EQ(sol.constrainedSubsetSum(nums, 2), 37);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{-1, -2, -3};
  EXPECT_EQ(sol.constrainedSubsetSum(nums, 1), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{10, -2, -10, -5, 20};
  EXPECT_EQ(sol.constrainedSubsetSum(nums, 2), 23);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{10,  -2, 3, 1, 4,  1,  5, 9, 2,   6, -10, 2,  7, 1, -5, 20, 8, 2, -100};
  EXPECT_EQ(sol.constrainedSubsetSum(nums, 3), 81);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums{-5266, 4019, 7336, -3681, -5767};
  EXPECT_EQ(sol.constrainedSubsetSum(nums, 2), 11355);
}

