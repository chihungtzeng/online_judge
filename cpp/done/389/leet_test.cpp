#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.findTheDifference("abcd", "abcde"), 'e');
  EXPECT_EQ(sol.findTheDifference("abcdfg", "gfcxdab"), 'x');
}

