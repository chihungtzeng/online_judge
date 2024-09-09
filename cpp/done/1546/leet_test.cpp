#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1, 1, 1, 1, 1};
  EXPECT_EQ(sol.maxNonOverlapping(nums, 2), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{-1, 3, 5, 1, 4, 2, -9};
  EXPECT_EQ(sol.maxNonOverlapping(nums, 6), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{-2, 6, 6, 3, 5, 4, 1, 2, 8};
  EXPECT_EQ(sol.maxNonOverlapping(nums, 10), 3);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums{0, 0, 0};
  EXPECT_EQ(sol.maxNonOverlapping(nums, 0), 3);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums{-1, -2, 8, -3, 8, -5, 5, -4, 5, 4, 1};
  EXPECT_EQ(sol.maxNonOverlapping(nums, 5), 5);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> nums{3, 0,  2, 0, 2, 3, 3, 0, 0, 2, 1, 1, 1,  0, -1, -1,
                   1, -1, 1, 0, 2, 0, 0, 3, 0, 0, 3, 1, 0,  2, 0,  -1,
                   2, -1, 1, 1, 3, 0, 2, 3, 3, 0, 0, 2, -1, 1};
  EXPECT_EQ(sol.maxNonOverlapping(nums, 3), 12);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> nums{3, 0,  2};
  EXPECT_EQ(sol.maxNonOverlapping(nums, 3), 1);
}

