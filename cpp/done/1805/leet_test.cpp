#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numDifferentIntegers("a123bc34d8ef34"), 3);
  EXPECT_EQ(sol.numDifferentIntegers("leet1234code234"), 2);
  EXPECT_EQ(sol.numDifferentIntegers("a1b01c001"), 1);
  EXPECT_EQ(sol.numDifferentIntegers("a0b00c000"), 1);
  EXPECT_EQ(sol.numDifferentIntegers("abbcccddd"), 0);
  EXPECT_EQ(sol.numDifferentIntegers("abbcccddd123456"), 1);
  EXPECT_EQ(sol.numDifferentIntegers("167278959591294"), 1);
}

