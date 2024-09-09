#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maximumTime("2?:?0"), "23:50");
  EXPECT_EQ(sol.maximumTime("0?:3?"), "09:39");
  EXPECT_EQ(sol.maximumTime("1?:22"), "19:22");
}

