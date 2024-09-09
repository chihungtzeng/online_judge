#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.integerReplacement(8), 3);
  EXPECT_EQ(sol.integerReplacement(7), 4);
  EXPECT_EQ(sol.integerReplacement(2147483647), 32);
  EXPECT_EQ(sol.integerReplacement(100001), 22);
}

