#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
vector<int> nums = {1000,100,10,2};
  EXPECT_EQ(sol.optimalDivision(nums), "1000/(100/10/2)");
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2,3,4};
  EXPECT_EQ(sol.optimalDivision(nums), "2/(3/4)");
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {2};
  EXPECT_EQ(sol.optimalDivision(nums), "2");
}

