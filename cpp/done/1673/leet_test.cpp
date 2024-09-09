#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {3, 5, 2, 6};
  int k = 2;
  vector<int> expect{2, 6};
  EXPECT_EQ(sol.mostCompetitive(nums, k), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2, 4, 3, 3, 5, 4, 9, 6};
  int k = 4;
  vector<int> expect{2, 3, 3, 4};
  EXPECT_EQ(sol.mostCompetitive(nums, k), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {71, 18, 52, 29, 55, 73, 24, 42, 66, 8, 80, 2};
  int k = 3;
  vector<int> expect{8, 80, 2};
  EXPECT_EQ(sol.mostCompetitive(nums, k), expect);
}

