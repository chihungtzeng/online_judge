#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numSub("0110111"), 9);
  EXPECT_EQ(sol.numSub("101"), 2);
  EXPECT_EQ(sol.numSub("111111"), 21);
  EXPECT_EQ(sol.numSub("000"), 0);
}

