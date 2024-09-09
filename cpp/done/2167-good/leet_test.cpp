#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  string s = "1100101";
  EXPECT_EQ(sol.minimumTime(s), 5);
  s = "0010";
  EXPECT_EQ(sol.minimumTime(s), 2);
  s = "";
  EXPECT_EQ(sol.minimumTime(s), 0);
  s = "0000000000000000000000000000000000";
  EXPECT_EQ(sol.minimumTime(s), 0);
}
TEST(kk, t2) {
  Solution sol;
  string s = "010110";
  EXPECT_EQ(sol.minimumTime(s), 5);
}


