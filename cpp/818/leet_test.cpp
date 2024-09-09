#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.racecar(1), 1);
  EXPECT_EQ(sol.racecar(2), 4);
  EXPECT_EQ(sol.racecar(3), 2);
  EXPECT_EQ(sol.racecar(6), 5);
  EXPECT_EQ(sol.racecar(10000), 45);
}


