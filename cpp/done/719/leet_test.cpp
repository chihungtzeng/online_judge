#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,3,1};

  EXPECT_EQ(sol.smallestDistancePair(nums, 1), 0);
  EXPECT_EQ(sol.smallestDistancePair(nums, 2), 2);
  EXPECT_EQ(sol.smallestDistancePair(nums, 3), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1,3,10,10,100};

  EXPECT_EQ(sol.smallestDistancePair(nums, 1), 0);
  EXPECT_EQ(sol.smallestDistancePair(nums, 2), 2);
  EXPECT_EQ(sol.smallestDistancePair(nums, 3), 7);
  EXPECT_EQ(sol.smallestDistancePair(nums, 4), 7);
  EXPECT_EQ(sol.smallestDistancePair(nums, 5), 9);
  EXPECT_EQ(sol.smallestDistancePair(nums, 6), 9);
  EXPECT_EQ(sol.smallestDistancePair(nums, 7), 90);
  EXPECT_EQ(sol.smallestDistancePair(nums, 8), 90);
  EXPECT_EQ(sol.smallestDistancePair(nums, 9), 97);
  EXPECT_EQ(sol.smallestDistancePair(nums, 10), 99);
}

