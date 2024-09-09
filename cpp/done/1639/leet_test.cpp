#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words = {"acca", "bbbb", "caca"};
  string target = "aba";
  EXPECT_EQ(sol.numWays(words, target), 6);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> words = {"abba", "baab"};
  string target = "bab";
  EXPECT_EQ(sol.numWays(words, target), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> words = {"abcd"};
  string target = "abcd";
  EXPECT_EQ(sol.numWays(words, target), 1);
}

TEST(kk, t4) {
  Solution sol;
  vector<string> words = {"abab", "baba", "abba", "baab"};
  string target = "abba";
  EXPECT_EQ(sol.numWays(words, target), 16);
}

TEST(kk, t5) {
  Solution sol;
  vector<string> words = {
      "cbabddddbc", "addbaacbbd", "cccbacdccd", "cdcaccacac", "dddbacabbd",
      "bdbdadbccb", "ddadbacddd", "bbccdddadd", "dcabaccbbd", "ddddcddadc",
      "bdcaaaabdd", "adacdcdcdd", "cbaaadbdbb", "bccbabcbab", "accbdccadd",
      "dcccaaddbc", "cccccacabd", "acacdbcbbc", "dbbdbaccca", "bdbddbddda",
      "daabadbacb", "baccdbaada", "ccbabaabcb", "dcaabccbbb", "bcadddaacc",
      "acddbbdccb", "adbddbadab", "dbbcdcbcdd", "ddbabbadbb", "bccbcbbbab",
      "dabbbdbbcb", "dacdabadbb", "addcbbabab", "bcbbccadda", "abbcacadac",
      "ccdadcaada", "bcacdbccdb"};
  string target = "bcbbcccc";
  EXPECT_EQ(sol.numWays(words, target), 677452090);
}

