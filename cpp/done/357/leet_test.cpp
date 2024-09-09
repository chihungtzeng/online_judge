#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countNumbersWithUniqueDigits(0), 1);
  EXPECT_EQ(sol.countNumbersWithUniqueDigits(1), 10);
  EXPECT_EQ(sol.countNumbersWithUniqueDigits(2), 91);
  EXPECT_EQ(sol.countNumbersWithUniqueDigits(10), 8877691);
  EXPECT_EQ(sol.countNumbersWithUniqueDigits(11), 8877691);
  EXPECT_EQ(sol.countNumbersWithUniqueDigits(2100000), 8877691);
}

