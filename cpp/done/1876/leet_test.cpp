#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countGoodSubstrings("xyzzaz"), 1);
}

TEST(kk, t2) {
  Solution sol;

  EXPECT_EQ(sol.countGoodSubstrings("aababcabc"), 4);
}

