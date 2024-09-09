#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.reverse(123), 321);
  EXPECT_EQ(sol.reverse(-123), -321);
  EXPECT_EQ(sol.reverse(120), 21);
  EXPECT_EQ(sol.reverse(1234567899), 0);
  EXPECT_EQ(sol.reverse(0), 0);
}

