#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.findComplement(1), 0);
  EXPECT_EQ(sol.findComplement(5), 2);
}

