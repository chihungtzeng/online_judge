#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numOfWays(1), 12);
  EXPECT_EQ(sol.numOfWays(2), 54);
  EXPECT_EQ(sol.numOfWays(3), 246);
  EXPECT_EQ(sol.numOfWays(7), 106494);
  EXPECT_EQ(sol.numOfWays(5000), 30228214);
}

