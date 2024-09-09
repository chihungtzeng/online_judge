#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int lo = 12, hi = 15, k = 2;
  EXPECT_EQ(sol.getKth(lo, hi, k), 13);
}
TEST(kk, t2) {
  Solution sol;
  int lo = 1, hi = 1, k = 1;
  EXPECT_EQ(sol.getKth(lo, hi, k), 1);
}

TEST(kk, t3) {
  Solution sol;
  int lo = 7, hi = 11, k = 4;
  EXPECT_EQ(sol.getKth(lo, hi, k), 7);
}

TEST(kk, t4) {
  Solution sol;
  int lo = 10, hi = 20, k = 5;
  EXPECT_EQ(sol.getKth(lo, hi, k), 13);
}

TEST(kk, t5) {
  Solution sol;
   int lo = 1, hi = 1000, k = 777;
  EXPECT_EQ(sol.getKth(lo, hi, k), 570);
}

