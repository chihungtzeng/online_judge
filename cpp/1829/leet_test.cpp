#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {0, 1, 1, 3};
  int maximumBit = 2;
  vector<int> expect{0, 3, 2, 3};
  EXPECT_EQ(sol.getMaximumXor(nums, maximumBit), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {2, 3, 4, 7};
  int maximumBit = 3;
  vector<int> expect{5, 2, 6, 5};
  EXPECT_EQ(sol.getMaximumXor(nums, maximumBit), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {0, 1, 2, 2, 5, 7};
  int maximumBit = 3;
  vector<int> expect{4, 3, 6, 4, 6, 7};
  EXPECT_EQ(sol.getMaximumXor(nums, maximumBit), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> nums = {0, 1, 2, 2, 5, 7, 99999, 100000};
  int maximumBit = 3;
  vector<int> expect{3, 3, 4, 3, 6, 4, 6, 7};
  EXPECT_EQ(sol.getMaximumXor(nums, maximumBit), expect);
}

