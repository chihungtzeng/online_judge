#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words = {"SEND", "MORE"};
  string result = "MONEY";
  EXPECT_EQ(sol.isSolvable(words, result), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> words = {"SIX", "SEVEN", "SEVEN"};
  string result = "TWENTY";
  EXPECT_EQ(sol.isSolvable(words, result), true);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> words = {"THIS", "IS", "TOO"};
  string result = "FUNNY";
  EXPECT_EQ(sol.isSolvable(words, result), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<string> words = {"LEET", "CODE"};
  string result = "POINT";
  EXPECT_EQ(sol.isSolvable(words, result), false);
}

TEST(kk, t5) {
  Solution sol;
  vector<string> words = {"A", "B"};
  string result = "A";
  EXPECT_EQ(sol.isSolvable(words, result), true);
}

