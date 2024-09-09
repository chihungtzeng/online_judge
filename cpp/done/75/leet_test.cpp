#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {2,0,2,1,1,0};
  vector<int> expect{0,0,1,1,2,2};
  sol.sortColors(nums);

  EXPECT_EQ(nums , expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2,0,1};
  vector<int> expect{0,1,2};
  sol.sortColors(nums);

  EXPECT_EQ(nums , expect);
}

