#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countOperations(2, 3), 3);
  EXPECT_EQ(sol.countOperations(10, 10), 1);
  EXPECT_EQ(sol.countOperations(12345, 1767), 84);
}

