#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.minRemoveToMakeValid("lee(t(c)o)de)"), "lee(t(c)o)de");
  EXPECT_EQ(sol.minRemoveToMakeValid("a)b(c)d"), "ab(c)d");
  EXPECT_EQ(sol.minRemoveToMakeValid("))(("), "");
  EXPECT_EQ(sol.minRemoveToMakeValid("(a(b(c)d)"), "a(b(c)d)");
}

