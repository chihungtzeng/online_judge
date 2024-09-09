#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.canConvertString("input", "ouput", 9), true);
  EXPECT_EQ(sol.canConvertString("abc", "bcd", 10), false);
  EXPECT_EQ(sol.canConvertString("aab", "bbb", 27), true);
}

