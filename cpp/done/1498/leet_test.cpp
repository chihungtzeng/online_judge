#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {5,2,4,1,7,6,8};
  int target = 16;

  EXPECT_EQ(sol.numSubseq(nums,target), 127);
}

