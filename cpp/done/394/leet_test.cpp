#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  string s = "3[a]2[bc]";
  EXPECT_EQ(sol.decodeString(s), "aaabcbc");
  EXPECT_EQ(sol.decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef");
  EXPECT_EQ(sol.decodeString("abc3[cd]xyz"), "abccdcdcdxyz");
//  EXPECT_EQ(sol.decodeString(), "");
}

TEST(kk, t2) {
  Solution sol;
  EXPECT_EQ(sol.decodeString("3[a2[c]]"), "accaccacc");
}
