#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.checkRecord(1), 3);
  EXPECT_EQ(sol.checkRecord(2), 8);
  EXPECT_EQ(sol.checkRecord(10101), 183236316);
  EXPECT_EQ(sol.checkRecord(100000), 749184020);
}

