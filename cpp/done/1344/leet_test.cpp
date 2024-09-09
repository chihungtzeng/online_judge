#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(abs(sol.angleClock(12, 30) - 165) <= 1e-5, true);
  EXPECT_EQ(abs(sol.angleClock(3, 30) - 75) <= 1e-5, true);
  EXPECT_EQ(abs(sol.angleClock(3, 15) - 7.5) <= 1e-5, true);
  EXPECT_EQ(abs(sol.angleClock(4, 50) - 155) <= 1e-5, true);
  EXPECT_EQ(abs(sol.angleClock(12, 0) - 0) <= 1e-5, true);
}

