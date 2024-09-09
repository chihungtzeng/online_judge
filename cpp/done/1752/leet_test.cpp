#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {3, 4, 5, 1, 2};
  EXPECT_EQ(sol.check(nums), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2, 1, 3, 4};
  EXPECT_EQ(sol.check(nums), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  EXPECT_EQ(sol.check(nums), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {1, 1, 1};
  EXPECT_EQ(sol.check(nums), true);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> nums = {2, 1};
  EXPECT_EQ(sol.check(nums), true);
}

TEST(kk, t6) {
  Solution sol;
  vector<int> nums = {100};
  EXPECT_EQ(sol.check(nums), true);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> nums = {3,1,2,2,4};
  EXPECT_EQ(sol.check(nums), false);
}
TEST(kk, t8) {
  Solution sol;
  vector<int> nums = {2,4,1,3};
  EXPECT_EQ(sol.check(nums), false);
}

TEST(kk, t9) {
  Solution sol;
  vector<int> nums = {6,10,6};
  EXPECT_EQ(sol.check(nums), true);
}

