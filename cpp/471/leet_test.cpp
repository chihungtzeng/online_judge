#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"


TEST(kk, t0) {
  Solution sol;
  EXPECT_EQ(sol.cmpr("a"), "a");
  EXPECT_EQ(sol.cmpr("aaa"), "aaa");
  EXPECT_EQ(sol.cmpr("aaaa"), "aaaa");
  EXPECT_EQ(sol.cmpr("aaaaa"), "5[a]");
  EXPECT_EQ(sol.cmpr("abcabcabc"), "3[abc]");
  EXPECT_EQ(sol.cmpr("abcdeabcde"), "2[abcde]");
}

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.encode("aaa"), "aaa");
  EXPECT_EQ(sol.encode("aaaaa"), "5[a]");
  EXPECT_EQ(sol.encode("aaaaaaaaaa"), "10[a]");
  EXPECT_EQ(sol.encode("aabcaabcd"), "2[aabc]d");
  EXPECT_EQ(sol.encode("abbbabbbcabbbabbbc"), "2[2[abbb]c]");
  EXPECT_EQ(sol.encode("abbbabbbc"), "2[abbb]c");
  EXPECT_EQ(sol.encode("abcdabcdeabcdabcde"), "2[2[abcd]e]");
  EXPECT_EQ(sol.encode("abcdabcdcabcdabcdcabcdabcdc"), "3[2[abcd]c]");
}

