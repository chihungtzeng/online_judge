#include "glog/logging.h"
#include "glog/stl_logging.h"
#include "leet.cpp"
#include <gtest/gtest.h>

TEST(kk, t1) {
  Solution sol;
  string s = "catsanddog";
  vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};
  vector<string> expect = {"cats and dog", "cat sand dog"};
  auto actual = sol.wordBreak(s, wordDict);

  std::sort(expect.begin(), expect.end());
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual.size(), expect.size());
  for (size_t i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expect[i], actual[i]);
  }
}

TEST(kk, t2) {
  Solution sol;
  string s = "pineapplepenapple";
  vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};
  vector<string> expect = {"pine apple pen apple", "pineapple pen apple",
                           "pine applepen apple"};
  auto actual = sol.wordBreak(s, wordDict);

  std::sort(expect.begin(), expect.end());
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual.size(), expect.size());
  for (size_t i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expect[i], actual[i]);
  }
}

TEST(kk, t3) {
  Solution sol;
  string s = "catsandog";
  vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
  vector<string> expect;
  auto actual = sol.wordBreak(s, wordDict);

  EXPECT_EQ(actual.size(), 0);
}

TEST(kk, t4) {
  Solution sol;
  string s = "apple";
  vector<string> wordDict{"apple"};
  vector<string> expect{"apple"};
  auto actual = sol.wordBreak(s, wordDict);

  std::sort(expect.begin(), expect.end());
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual.size(), expect.size());
  for (size_t i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expect[i], actual[i]);
  }
}

TEST(kk, t5) {
  Solution sol;
  string s = "aaaa";
  vector<string> wordDict{"a", "aa"};
  vector<string> expect{"a a a a", "aa a a", "a aa a", "a a aa", "aa aa"};
  auto actual = sol.wordBreak(s, wordDict);

  std::sort(expect.begin(), expect.end());
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual.size(), expect.size());
  for (size_t i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expect[i], actual[i]);
  }
}

TEST(kk, t6) {
  Solution sol;
  string s = "aaaaaaa";
  vector<string> wordDict{"aaaa","aa","a"};
  vector<string> expect{
      "a a a a a a a", "aa a a a a a", "a aa a a a a", "a a aa a a a",
      "aa aa a a a",   "aaaa a a a",   "a a a aa a a", "aa a aa a a",
      "a aa aa a a",   "a aaaa a a",   "a a a a aa a", "aa a a aa a",
      "a aa a aa a",   "a a aa aa a",  "aa aa aa a",   "aaaa aa a",
      "a a aaaa a",    "aa aaaa a",    "a a a a a aa", "aa a a a aa",
      "a aa a a aa",   "a a aa a aa",  "aa aa a aa",   "aaaa a aa",
      "a a a aa aa",   "aa a aa aa",   "a aa aa aa",   "a aaaa aa",
      "a a a aaaa",    "aa a aaaa",    "a aa aaaa"};

  auto actual = sol.wordBreak(s, wordDict);

  std::sort(expect.begin(), expect.end());
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual.size(), expect.size());
  for (size_t i = 0; i < actual.size(); i++) {
    EXPECT_EQ(expect[i], actual[i]);
  }
}

TEST(kk, t7) {
  Solution sol;
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

  vector<string> wordDict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  vector<string> expect{};
  auto actual = sol.wordBreak(s, wordDict);

  EXPECT_EQ(actual.size(), 0);
}

