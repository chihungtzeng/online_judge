#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maxNiceDivisors(5), 6);
  EXPECT_EQ(sol.maxNiceDivisors(8), 18);
  EXPECT_EQ(sol.maxNiceDivisors(1000000000), 897135186);
}

