#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.convertToBase7(100), "202");
  EXPECT_EQ(sol.convertToBase7(0), "0");
  EXPECT_EQ(sol.convertToBase7(-7), "-10");
  EXPECT_EQ(sol.convertToBase7(9), "12");
  EXPECT_EQ(sol.convertToBase7(5), "5");
  EXPECT_EQ(sol.convertToBase7(-5), "-5");
}

