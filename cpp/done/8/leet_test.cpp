#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.myAtoi("42"), 42);
  EXPECT_EQ(sol.myAtoi("   -42"), -42);
  EXPECT_EQ(sol.myAtoi("4193 with words"), 4193);
  EXPECT_EQ(sol.myAtoi("+"), 0);
  EXPECT_EQ(sol.myAtoi("+ 1234"), 0);
  EXPECT_EQ(sol.myAtoi("-"), 0);
  EXPECT_EQ(sol.myAtoi("- 1234"), 0);
  EXPECT_EQ(sol.myAtoi("   -2147483648"), -2147483648);
  EXPECT_EQ(sol.myAtoi("   -2147483649  aak"), -2147483648);
  EXPECT_EQ(sol.myAtoi("     2147483647   aak"), 2147483647);
  EXPECT_EQ(sol.myAtoi("     +2147483647   aak"), 2147483647);
  EXPECT_EQ(sol.myAtoi("     2147483648   aak"), 2147483647);
}

