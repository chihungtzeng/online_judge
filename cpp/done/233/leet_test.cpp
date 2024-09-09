#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countDigitOne(13), 6);
  EXPECT_EQ(sol.countDigitOne(57), 16);
  EXPECT_EQ(sol.countDigitOne(INT_MAX), 15);
  LOG(INFO) << INT_MAX;  // 2147483647
}

