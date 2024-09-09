#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.hasAllCodes("00110110",2), true);
  EXPECT_EQ(sol.hasAllCodes("00110",2), true);
  EXPECT_EQ(sol.hasAllCodes("0110",1), true);
  EXPECT_EQ(sol.hasAllCodes("0110",2), false);
  EXPECT_EQ(sol.hasAllCodes("0000000001011100",4), false);
}

