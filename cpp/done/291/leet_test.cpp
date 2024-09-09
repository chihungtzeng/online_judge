#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string pattern = "abab", s = "redblueredblue";
  EXPECT_EQ(sol.wordPatternMatch(pattern, s), true);

  pattern = "aaaa", s = "asdasdasdasd";
  EXPECT_EQ(sol.wordPatternMatch(pattern, s), true);

  pattern = "abab", s = "asdasdasdasd";
  EXPECT_EQ(sol.wordPatternMatch(pattern, s), true);

  pattern = "aabb", s = "xyzabcxzyabc";
  EXPECT_EQ(sol.wordPatternMatch(pattern, s), false);

  pattern = "ab", s = "cd";
  EXPECT_EQ(sol.wordPatternMatch(pattern, s), true);
  pattern = "ab", s = "c";
  EXPECT_EQ(sol.wordPatternMatch(pattern, s), false);
}


TEST(kk, t2) {
  Solution sol;
  string pattern, s;
  pattern = "aba", s = "aaaa";
  EXPECT_EQ(sol.wordPatternMatch(pattern, s), true);
}

TEST(kk, t3) {
  Solution sol;
  string pattern = "itwasthebestoftimes";
  string s = "ittwaastthhebesttoofttimes";

  EXPECT_EQ(sol.wordPatternMatch(pattern, s), true);
}
