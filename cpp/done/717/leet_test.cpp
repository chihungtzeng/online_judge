#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> bits{1, 0, 0};
  vector<int> bits2{1, 1, 1, 0};

  EXPECT_EQ(sol.isOneBitCharacter(bits), true);
  EXPECT_EQ(sol.isOneBitCharacter(bits2), false);
}

