#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string word = "aeiaaioaaaaeiiiiouuuooaauuaeiu";
  EXPECT_EQ(sol.longestBeautifulSubstring(word), 13);
}

TEST(kk, t2) {
  Solution sol;
  string word = "aeeeiiiioooauuuaeiou";
  EXPECT_EQ(sol.longestBeautifulSubstring(word), 5);
}

TEST(kk, t3) {
  Solution sol;
  string word = "a";
  EXPECT_EQ(sol.longestBeautifulSubstring(word), 0);
}

