#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.fractionAddition("-1/2+1/2"), "0/1");
  EXPECT_EQ(sol.fractionAddition("-1/2+1/2+1/3"), "1/3");
  EXPECT_EQ(sol.fractionAddition("1/3-1/2"), "-1/6");
  EXPECT_EQ(sol.fractionAddition("5/3+1/3"), "2/1");
}

