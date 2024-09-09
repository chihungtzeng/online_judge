#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.addStrings("123", "4567"), "4690");
  EXPECT_EQ(sol.addStrings("0", "4567"), "4567");
  EXPECT_EQ(sol.addStrings("9876", "4567"), "14443");
  EXPECT_EQ(sol.addStrings("", "4567"), "4567");
}

