#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  auto ret = sol.allPossibleFBT(7);

  EXPECT_EQ(ret.size(), 5);
}

TEST(kk, t2) {
  Solution sol;
  auto ret = sol.allPossibleFBT(3);

  EXPECT_EQ(ret.size(), 1);
}

