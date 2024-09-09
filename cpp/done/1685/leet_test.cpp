#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {2, 3, 5};
  vector<int> expect{4, 3, 5};
  EXPECT_EQ(sol.getSumAbsoluteDifferences(nums), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {1, 4, 6, 8, 10};
  vector<int> expect{24, 15, 13, 15, 21};
  EXPECT_EQ(sol.getSumAbsoluteDifferences(nums), expect);
}

