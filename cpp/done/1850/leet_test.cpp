#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string num = "5489355142";
  int k = 4;
  EXPECT_EQ(sol.getMinSwaps(num, k), 2);
}

TEST(kk, t2) {
  Solution sol;
  string num = "11112";
  int k = 4;
  EXPECT_EQ(sol.getMinSwaps(num, k), 4);
}

TEST(kk, t3) {
  Solution sol;
  string num = "00123";
  int k = 1;
  EXPECT_EQ(sol.getMinSwaps(num, k), 1);
}

TEST(kk, t4) {
  Solution sol;
  string num = "3141592627182";
  int k = 1000;
  EXPECT_EQ(sol.getMinSwaps(num, k), 21);
}

