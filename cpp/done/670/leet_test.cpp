#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maximumSwap(2736), 7236);
  EXPECT_EQ(sol.maximumSwap(9973), 9973);
  EXPECT_EQ(sol.maximumSwap(98368), 98863);
  for(int i=0; i<=10; i++){
  EXPECT_EQ(sol.maximumSwap(i), i);
  }
}

