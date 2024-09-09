#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countBinarySubstrings("00110011"), 6);
  EXPECT_EQ(sol.countBinarySubstrings("10101"), 4);
}

