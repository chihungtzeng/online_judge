#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;

  EXPECT_EQ(sol.findIntegers(0), 1);
  EXPECT_EQ(sol.findIntegers(1), 2);
  EXPECT_EQ(sol.findIntegers(2), 3);
  EXPECT_EQ(sol.findIntegers(3), 3);
  EXPECT_EQ(sol.findIntegers(4), 4);
  EXPECT_EQ(sol.findIntegers(5), 5);
  EXPECT_EQ(sol.findIntegers(6), 5);
  EXPECT_EQ(sol.findIntegers(1000000000), 2178309);
}

