#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> digits = {8, 1, 9};
  EXPECT_EQ(sol.largestMultipleOfThree(digits), "981");
}

TEST(kk, t2) {
  Solution sol;
  vector<int> digits = {8, 6, 7, 1, 0};
  EXPECT_EQ(sol.largestMultipleOfThree(digits), "8760");
}

TEST(kk, t3) {
  Solution sol;
  vector<int> digits = {1};
  EXPECT_EQ(sol.largestMultipleOfThree(digits), "");
}

TEST(kk, t4) {
  Solution sol;
  vector<int> digits = {0, 0, 0, 0, 0, 0};
  EXPECT_EQ(sol.largestMultipleOfThree(digits), "0");
}

