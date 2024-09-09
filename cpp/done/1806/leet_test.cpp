#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.reinitializePermutation(2), 1);
  EXPECT_EQ(sol.reinitializePermutation(4), 2);
  EXPECT_EQ(sol.reinitializePermutation(6), 4);
  EXPECT_EQ(sol.reinitializePermutation(1000), 36);
  EXPECT_EQ(sol.reinitializePermutation(988), 138);
}

