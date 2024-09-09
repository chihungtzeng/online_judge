#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string S = "abcd";
  vector<int> indexes = {0, 2};
  vector<string> sources = {"a", "cd"}, targets = {"eee", "ffff"};
  EXPECT_EQ(sol.findReplaceString(S, indexes, sources, targets), "eeebffff");
}

TEST(kk, t2) {
  Solution sol;
  string S = "abcd";
  vector<int> indexes = {0, 2};
  vector<string> sources = {"ab", "ec"}, targets = {"eee", "ffff"};
  EXPECT_EQ(sol.findReplaceString(S, indexes, sources, targets), "eeecd");
}

TEST(kk, t3) {
  Solution sol;
  string S = "vmokgggqzp";
  vector<int> indexes = {3,5,1};
  vector<string> sources = {"kg", "ggq", "mo"}, targets = {"s", "so", "bfr"};
  EXPECT_EQ(sol.findReplaceString(S, indexes, sources, targets), "vbfrssozp");
}

