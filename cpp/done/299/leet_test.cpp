#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.getHint("1807", "7810"), "1A3B");
  EXPECT_EQ(sol.getHint("1123", "0111"), "1A1B");
}

