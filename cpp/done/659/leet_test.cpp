#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,2,3,3,4,5};
  EXPECT_EQ(sol.isPossible(nums), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1,2,3,3,4,4,5,5};
  EXPECT_EQ(sol.isPossible(nums), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{1,2,3,4,4,5};
  EXPECT_EQ(sol.isPossible(nums), false);
}

