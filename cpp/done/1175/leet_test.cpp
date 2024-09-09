#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numPrimeArrangements(1), 1);
  EXPECT_EQ(sol.numPrimeArrangements(2), 1);
  EXPECT_EQ(sol.numPrimeArrangements(3), 2);
  EXPECT_EQ(sol.numPrimeArrangements(4), 4);
  EXPECT_EQ(sol.numPrimeArrangements(5), 12);
  EXPECT_EQ(sol.numPrimeArrangements(100), 682289015);
}

