#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.integerBreak(2), 1);
  EXPECT_EQ(sol.integerBreak(3), 2);
  EXPECT_EQ(sol.integerBreak(4), 4);
  EXPECT_EQ(sol.integerBreak(5), 6);
  EXPECT_EQ(sol.integerBreak(10), 36);

}

