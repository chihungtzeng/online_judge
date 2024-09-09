#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.monotoneIncreasingDigits(10), 9);
  EXPECT_EQ(sol.monotoneIncreasingDigits(1234), 1234);
  EXPECT_EQ(sol.monotoneIncreasingDigits(332), 299);
  EXPECT_EQ(sol.monotoneIncreasingDigits(3141592), 2999999);
  //EXPECT_EQ(sol.monotoneIncreasingDigits(), );
}

