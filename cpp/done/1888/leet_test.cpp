#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minFlips("111000"), 2);
  EXPECT_EQ(sol.minFlips("010"), 0);
  EXPECT_EQ(sol.minFlips("1110"), 1);
  EXPECT_EQ(sol.minFlips("01001001101"), 2);
}

TEST(kk, t2) {
  Solution sol;
  string s = "1011110011010110000010110001111000111010111101001010100100011101010111010101001010000011010000100001";
  EXPECT_EQ(sol.minFlips(s), 48);
}

