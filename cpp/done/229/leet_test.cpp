#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {3,2,3};
  vector<int> expect{3};
  EXPECT_EQ(sol.majorityElement(nums), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1};
  vector<int> expect{1};
  EXPECT_EQ(sol.majorityElement(nums), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1,2};
  vector<int> expect{1, 2};
  EXPECT_EQ(sol.majorityElement(nums), expect);
}

