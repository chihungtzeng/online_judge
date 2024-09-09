#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string S = "heeellooo";
  vector<string> words = {"hello", "hi", "helo"};
  EXPECT_EQ(sol.expressiveWords(S, words), 1);
}

TEST(kk, t2) {
  Solution sol;
  string S = "aaa";
  vector<string> words = {"aaaa"};
  EXPECT_EQ(sol.expressiveWords(S, words), 0);
}

TEST(kk, t3) {
  Solution sol;
  string S = "heeellooo";
  vector<string> words = {"axxxrrzzz"};
  EXPECT_EQ(sol.expressiveWords(S, words), 0);
}

TEST(kk, t4) {
  Solution sol;
  string S = "dddiiiinnssssssoooo";
  vector<string> words = {"dinnssoo",   "ddinso",  "ddiinnso",
                          "ddiinnssoo", "ddiinso", "dinsoo",
                          "ddiinsso",   "dinssoo", "dinso"};
  EXPECT_EQ(sol.expressiveWords(S, words), 3);
}

