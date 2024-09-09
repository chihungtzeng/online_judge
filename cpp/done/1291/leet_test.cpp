#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int low = 100, high = 300;
  vector<int> expect{123, 234};
  EXPECT_EQ(sol.sequentialDigits(low, high), expect);
}

TEST(kk, t2) {
  Solution sol;
  int low = 1000, high = 13000;
  vector<int> expect{1234, 2345, 3456, 4567, 5678, 6789, 12345};
  EXPECT_EQ(sol.sequentialDigits(low, high), expect);
}

