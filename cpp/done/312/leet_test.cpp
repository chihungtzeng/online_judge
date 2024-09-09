#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{3,1,5,8};

  EXPECT_EQ(sol.maxCoins(nums), 167);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2};

  EXPECT_EQ(sol.maxCoins(nums), 3414);
}

