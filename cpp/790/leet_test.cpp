#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numTilings(1), 1);
  EXPECT_EQ(sol.numTilings(2), 2);
  EXPECT_EQ(sol.numTilings(3), 5);
  EXPECT_EQ(sol.numTilings(4), 11);
  EXPECT_EQ(sol.numTilings(1000), 979232805);
}

