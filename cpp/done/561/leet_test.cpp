#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,4,3,2};

  EXPECT_EQ(sol.arrayPairSum(nums), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{3,1,4,1,5,9,2,6,2,7,1,8,2,8};

  EXPECT_EQ(sol.arrayPairSum(nums), 27);
}

