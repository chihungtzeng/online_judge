#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.largestOddNumber("52"), "5");
  EXPECT_EQ(sol.largestOddNumber("4206"), "");
  EXPECT_EQ(sol.largestOddNumber("35427"), "35427");
}

