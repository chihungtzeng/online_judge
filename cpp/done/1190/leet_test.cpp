#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.reverseParentheses("(abcd)"), "dcba");
  EXPECT_EQ(sol.reverseParentheses("(u(love)i)"), "iloveu");
  EXPECT_EQ(sol.reverseParentheses("(ed(et(oc))el)"), "leetcode");
  EXPECT_EQ(sol.reverseParentheses("a(bcdefghijkl(mno)p)q"), "apmnolkjihgfedcbq");
  EXPECT_EQ(sol.reverseParentheses("apmnolkjihgfedcbq"), "apmnolkjihgfedcbq");
  EXPECT_EQ(sol.reverseParentheses(""), "");
}

