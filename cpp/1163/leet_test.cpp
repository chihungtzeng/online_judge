#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.lastSubstring("abab"), "bab");
  EXPECT_EQ(sol.lastSubstring("leetcode"), "tcode");
  EXPECT_EQ(sol.lastSubstring("a"), "a");
  EXPECT_EQ(sol.lastSubstring("aa"), "aa");
  EXPECT_EQ(sol.lastSubstring("aba"), "ba");
  EXPECT_EQ(sol.lastSubstring("lexicographicallymaximumsubstringisbab"), "ymaximumsubstringisbab");
  EXPECT_EQ(sol.lastSubstring("cacacb"), "cb");
  EXPECT_EQ(sol.lastSubstring("cdcdcb"), "dcdcb");
  EXPECT_EQ(sol.lastSubstring("aaaaaaaaaaaaaaaaaaaaa"), "aaaaaaaaaaaaaaaaaaaaa");
}

TEST(kk, t2){
  Solution sol;
  string s(400000, 'a');
  EXPECT_EQ(sol.lastSubstring(s), s);
}

