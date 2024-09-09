#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.longestAwesome("3242415"), 5);
  EXPECT_EQ(sol.longestAwesome("12345678"), 1);
  EXPECT_EQ(sol.longestAwesome("213123"), 6);
  EXPECT_EQ(sol.longestAwesome("00"), 2);

}

