#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.addDigits(38), 2);
  EXPECT_EQ(sol.addDigits(10), 1);
  for(int i=0; i<10; i++)
  {
    EXPECT_EQ(sol.addDigits(i), i);
  }
}

