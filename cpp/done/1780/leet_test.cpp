#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.checkPowersOfThree(1), true);
  EXPECT_EQ(sol.checkPowersOfThree(2), false);
  EXPECT_EQ(sol.checkPowersOfThree(3), true);
  EXPECT_EQ(sol.checkPowersOfThree(12), true);
  EXPECT_EQ(sol.checkPowersOfThree(91), true);
  EXPECT_EQ(sol.checkPowersOfThree(21), false);
}

