#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  EXPECT_EQ(sol.makeLargestSpecial("101100"), "110010");
  EXPECT_EQ(sol.makeLargestSpecial("11011000"), "11100100");
  EXPECT_EQ(sol.makeLargestSpecial("110111001000"), "111100100100");
}

