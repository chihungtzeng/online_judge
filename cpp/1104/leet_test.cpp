#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> expect{1, 3, 4, 14};
  EXPECT_EQ(sol.pathInZigZagTree(14), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> expect{1, 2, 6, 10, 26};
  EXPECT_EQ(sol.pathInZigZagTree(26), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> expect{1,     3,     4,     15,     17,     61,     69,
                     244,   279,   976,   1118,   3906,   4475,   15625,
                     17901, 62500, 71607, 250000, 286431, 1000000};
  EXPECT_EQ(sol.pathInZigZagTree(1e6), expect);
}
TEST(kk, t4) {
  Solution sol;
  vector<int> expect{1};
  EXPECT_EQ(sol.pathInZigZagTree(1), expect);
}
TEST(kk, t5) {
  Solution sol;
  vector<int> expect{1,3,4,15,16};
  EXPECT_EQ(sol.pathInZigZagTree(16), expect);
}
