#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.canReach("011010", 2, 3), true);
  EXPECT_EQ(sol.canReach("01101110", 2, 3), false);
  EXPECT_EQ(sol.canReach("0100100010", 3, 4), true);
}

