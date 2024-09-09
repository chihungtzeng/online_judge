#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.canWinNim(4), false);
  EXPECT_EQ(sol.canWinNim(5), true);
  EXPECT_EQ(sol.canWinNim(6), true);
  EXPECT_EQ(sol.canWinNim(7), true);
  EXPECT_EQ(sol.canWinNim(8), false);
}

