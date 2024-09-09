#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minOperations("0100"), 1);
  EXPECT_EQ(sol.minOperations("10"), 0);
  EXPECT_EQ(sol.minOperations("1111"), 2);
}

