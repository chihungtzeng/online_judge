#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.smallestNumber(0), 0);
  EXPECT_EQ(sol.smallestNumber(-1), -1);
  EXPECT_EQ(sol.smallestNumber(-10), -10);
  EXPECT_EQ(sol.smallestNumber(-19), -91);
  EXPECT_EQ(sol.smallestNumber(310), 103);
  EXPECT_EQ(sol.smallestNumber(-7650), -7650);
  EXPECT_EQ(sol.smallestNumber(-765000000000), -765000000000);
  EXPECT_EQ(sol.smallestNumber(7650), 5067);
  EXPECT_EQ(sol.smallestNumber(765000000000), 500000000067);
}

