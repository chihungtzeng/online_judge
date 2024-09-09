#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kerker, t1) {
  Solution sol;

  EXPECT_EQ(sol.trailingZeroes(3), 0);
  EXPECT_EQ(sol.trailingZeroes(5), 1);
  EXPECT_EQ(sol.trailingZeroes(101), 24);
  EXPECT_EQ(sol.trailingZeroes(-1), 0);
  EXPECT_EQ(sol.trailingZeroes(1073741824), 268435446);
  EXPECT_EQ(sol.trailingZeroes(1220703125), 305175781);
}

