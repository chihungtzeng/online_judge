#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.getHappyString(1,3), "c");
  EXPECT_EQ(sol.getHappyString(1,4), "");
  EXPECT_EQ(sol.getHappyString(3,9), "cab");
  EXPECT_EQ(sol.getHappyString(2,7), "");
  EXPECT_EQ(sol.getHappyString(10,100), "abacbabacb");
}

