#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.characterReplacement("ABAB", 2), 4);
  EXPECT_EQ(sol.characterReplacement("AABABBA", 1), 4);
}

