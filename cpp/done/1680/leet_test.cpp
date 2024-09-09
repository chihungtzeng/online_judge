#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.concatenatedBinary(1), 1);
  EXPECT_EQ(sol.concatenatedBinary(3), 27);
  EXPECT_EQ(sol.concatenatedBinary(12), 505379714);
  EXPECT_EQ(sol.concatenatedBinary(100000), 757631812);
  EXPECT_EQ(sol.concatenatedBinary(99871), 942193926);
  EXPECT_EQ(sol.concatenatedBinary(49241), 220194883);
}

