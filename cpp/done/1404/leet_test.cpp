#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numSteps("1101"), 6);
  EXPECT_EQ(sol.numSteps("10"), 1);
  EXPECT_EQ(sol.numSteps("11"), 3);
  EXPECT_EQ(sol.numSteps("1"), 0);
}

