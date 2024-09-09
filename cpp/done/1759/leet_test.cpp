#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countHomogenous("abbcccaa"), 13);
  EXPECT_EQ(sol.countHomogenous("xy"), 2);
  EXPECT_EQ(sol.countHomogenous("x"), 1);
  EXPECT_EQ(sol.countHomogenous("zzzzz"), 15);
}

