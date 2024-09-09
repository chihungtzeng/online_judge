#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.checkZeroOnes("1101"), true);
  EXPECT_EQ(sol.checkZeroOnes("111000"), false);
  EXPECT_EQ(sol.checkZeroOnes("110100010"), false);
}

