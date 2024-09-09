#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,12,-5,-6,50,3};
  int k=4;

  EXPECT_EQ(sol.findMaxAverage(nums, k), 12.75);
}

