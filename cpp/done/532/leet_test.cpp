#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{3,1,4,1,5};

  EXPECT_EQ(sol.findPairs(nums, 2), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1,2,3,4,5};

  EXPECT_EQ(sol.findPairs(nums, 1), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{1,3,1,5,4};

  EXPECT_EQ(sol.findPairs(nums, 0), 1);
}

