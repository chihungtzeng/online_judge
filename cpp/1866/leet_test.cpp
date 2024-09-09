#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.rearrangeSticks(3, 2), 3);
  EXPECT_EQ(sol.rearrangeSticks(5, 5), 1);
  EXPECT_EQ(sol.rearrangeSticks(20, 11), 647427950);
}

