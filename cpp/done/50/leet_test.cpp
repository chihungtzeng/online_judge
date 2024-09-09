#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  double x = 2.00000;
  int n = 10;

  auto actual = sol.myPow(x, n);
  EXPECT_TRUE(abs(actual - 1024.00000) <= 0.00001);

  x = 2.10000; n = 3;
  actual = sol.myPow(x, n);
  EXPECT_TRUE(abs(actual - 9.26100) <= 0.00001);

  x = 2.00000, n = -2;
  actual = sol.myPow(x, n);
  EXPECT_TRUE(abs(actual - 0.25) <= 0.00001);

  n = INT_MIN;
  uint32_t p = -(n + 1);
  p++;
  LOG(INFO) << n << ", " << p;
}

