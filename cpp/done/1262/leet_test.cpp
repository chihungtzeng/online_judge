#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {1,2,3,4,4};
  EXPECT_EQ(sol.maxSumDivThree(nums), 12);
}
TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2,19,6,16,5,10,7,4,11,6};

  EXPECT_EQ(sol.maxSumDivThree(nums), 84);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {3,6,5,1,8};

  EXPECT_EQ(sol.maxSumDivThree(nums), 18);
}

