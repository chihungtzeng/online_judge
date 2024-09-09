#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.kthFactor(12, 3), 3);
  EXPECT_EQ(sol.kthFactor(7, 2), 7);
  EXPECT_EQ(sol.kthFactor(4,4), -1);
  EXPECT_EQ(sol.kthFactor(1,1), 1);
  EXPECT_EQ(sol.kthFactor(1000,3), 4);
  EXPECT_EQ(sol.kthFactor(47,2), 47);
  EXPECT_EQ(sol.kthFactor(106,4), 106);
}

