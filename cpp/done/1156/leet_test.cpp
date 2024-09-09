#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.maxRepOpt1("ababa"), 3);
  EXPECT_EQ(sol.maxRepOpt1("aaabaaa"), 6);
  EXPECT_EQ(sol.maxRepOpt1("aaabbaaa"), 4);
  EXPECT_EQ(sol.maxRepOpt1("aaaabbcaaa"), 5);
  EXPECT_EQ(sol.maxRepOpt1("aaabbcaaaa"), 5);
  EXPECT_EQ(sol.maxRepOpt1("aaaaa"), 5);
  EXPECT_EQ(sol.maxRepOpt1("abcdef"), 1);
}

