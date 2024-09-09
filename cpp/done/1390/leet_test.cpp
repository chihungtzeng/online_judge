#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums = {21, 4, 7};
  EXPECT_EQ(sol.sumFourDivisors(nums), 32);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums = {21, 8};
  EXPECT_EQ(sol.sumFourDivisors(nums), 32 + 1 + 2 + 4+ 8);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums = {90779,36358,90351,75474,32986};

  EXPECT_EQ(sol.sumFourDivisors(nums), 147258);
}

