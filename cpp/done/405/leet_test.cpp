#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.toHex(0), "0");
  EXPECT_EQ(sol.toHex(26), "1a");
  EXPECT_EQ(sol.toHex(-1),      "ffffffff");
  EXPECT_EQ(sol.toHex(INT_MIN), "80000000");
}

