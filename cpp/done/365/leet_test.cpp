#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_TRUE(sol.canMeasureWater(3,5,4));
  EXPECT_FALSE(sol.canMeasureWater(2,6,5));
}

