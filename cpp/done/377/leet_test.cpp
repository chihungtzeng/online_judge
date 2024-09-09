#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1,2,3};
  int target=4;

  EXPECT_EQ(sol.combinationSum4(nums, target), 7);
}

