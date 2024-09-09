#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  EXPECT_EQ(sol.fractionToDecimal(1, 2), "0.5");
  EXPECT_EQ(sol.fractionToDecimal(2,1), "2");
  EXPECT_EQ(sol.fractionToDecimal(2,3), "0.(6)");
  EXPECT_EQ(sol.fractionToDecimal(29, 7), "4.(142857)");
  EXPECT_EQ(sol.fractionToDecimal(-29, 7), "-4.(142857)");
  EXPECT_EQ(sol.fractionToDecimal(29, -7), "-4.(142857)");
  EXPECT_EQ(sol.fractionToDecimal(-29, -7), "4.(142857)");
  EXPECT_EQ(sol.fractionToDecimal(17, 16), "1.0625");
  EXPECT_EQ(sol.fractionToDecimal(313845, 99900), "3.14(159)");
  EXPECT_EQ(sol.fractionToDecimal(2147483647, 1), "2147483647");
  EXPECT_EQ(sol.fractionToDecimal(2147483647, -1), "-2147483647");
  EXPECT_EQ(sol.fractionToDecimal(-2147483647, 1), "-2147483647");
  EXPECT_EQ(sol.fractionToDecimal(-2147483647, -1), "2147483647");
  EXPECT_EQ(sol.fractionToDecimal(-2147483648, 1), "-2147483648");
  EXPECT_EQ(sol.fractionToDecimal(-2147483648, -1), "2147483648");
  EXPECT_EQ(sol.fractionToDecimal(-1, -2147483648), "0.0000000004656612873077392578125");
  EXPECT_EQ(sol.fractionToDecimal(0, 2), "0");
  EXPECT_EQ(sol.fractionToDecimal(0, -2), "0");
  EXPECT_EQ(sol.fractionToDecimal(500, 10), "50");

}

TEST(kk, t2) {
  Solution sol;
  EXPECT_EQ(sol.fractionToDecimal(500, 10), "50");
}
