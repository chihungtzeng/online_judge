#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.totalMoney(4), 10);
  EXPECT_EQ(sol.totalMoney(7), 28);
  EXPECT_EQ(sol.totalMoney(10), 37);
  EXPECT_EQ(sol.totalMoney(20), 96);
  EXPECT_EQ(sol.totalMoney(1000), 74926);
}

