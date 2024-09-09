#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string binary = "000110";
  EXPECT_EQ(sol.maximumBinaryString(binary), "111011");
}

TEST(kk, t2) {
  Solution sol;
  string binary = "01";
  EXPECT_EQ(sol.maximumBinaryString(binary), "01");
}

TEST(kk, t3) {
  Solution sol;
  string binary = "01111001100000110010";
  EXPECT_EQ(sol.maximumBinaryString(binary), "11111111110111111111");
}

TEST(kk, t4) {
  Solution sol;
  string binary = "11";
  EXPECT_EQ(sol.maximumBinaryString(binary), "11");
}

