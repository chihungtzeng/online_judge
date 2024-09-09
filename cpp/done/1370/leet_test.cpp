#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.sortString("aaaabbbbcccc"), "abccbaabccba");
  EXPECT_EQ(sol.sortString("rat"), "art");
  EXPECT_EQ(sol.sortString("leetcode"), "cdelotee");
  EXPECT_EQ(sol.sortString("ggggggg"), "ggggggg");
  EXPECT_EQ(sol.sortString("spo"), "ops");
  EXPECT_EQ(sol.sortString("s"), "s");
}

