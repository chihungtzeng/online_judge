#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {11,7,2,15};

  EXPECT_EQ(sol.countElements(nums), 2);
  nums = {-3,3,3,90};
  EXPECT_EQ(sol.countElements(nums), 2);

  nums = {90};
  EXPECT_EQ(sol.countElements(nums), 0);

  nums = {90, 90, 90};
  EXPECT_EQ(sol.countElements(nums), 0);
  nums = {90, 90, 90, 92, 92, 92};
  EXPECT_EQ(sol.countElements(nums), 0);
  nums = {89, 90, 90, 90, 92, 92, 92};
  EXPECT_EQ(sol.countElements(nums), 3);
}

