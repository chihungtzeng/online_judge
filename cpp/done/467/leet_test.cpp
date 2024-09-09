#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.findSubstringInWraproundString(""), 0);
  EXPECT_EQ(sol.findSubstringInWraproundString("a"), 1);
  EXPECT_EQ(sol.findSubstringInWraproundString("cac"), 2);
  EXPECT_EQ(sol.findSubstringInWraproundString("zab"), 6);
  EXPECT_EQ(sol.findSubstringInWraproundString("zabzab"), 6);
  EXPECT_EQ(sol.findSubstringInWraproundString("zabcdefghijklmnopqrstuvwxyza"), 403);
}

