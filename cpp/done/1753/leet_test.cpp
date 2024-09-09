#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maximumScore(2, 4, 6), 6);
  EXPECT_EQ(sol.maximumScore(4, 4, 6), 7);
  EXPECT_EQ(sol.maximumScore(1,8,8), 8);
}

