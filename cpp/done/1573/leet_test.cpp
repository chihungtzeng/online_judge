#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numWays("10101"), 4);
  EXPECT_EQ(sol.numWays("1001"), 0);
  EXPECT_EQ(sol.numWays("0000"), 3);
  EXPECT_EQ(sol.numWays("100100010100110"), 12);
  string s = "1" + string(50000, '0') + '1' + string(49997, '0') + '1';
  EXPECT_EQ(sol.numWays(s), 12);
}

