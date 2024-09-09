#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.reorderSpaces("  this   is  a sentence "), "this   is   a   sentence");
  EXPECT_EQ(sol.reorderSpaces(" practice   makes   perfect"), "practice   makes   perfect ");
  EXPECT_EQ(sol.reorderSpaces("a"), "a");
}

