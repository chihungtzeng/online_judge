#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words = {"dog", "cat", "dad", "good"};
  vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
  vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
                       0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_EQ(sol.maxScoreWords(words, letters, score), 23);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> words = {"xxxz", "ax", "bx", "cx"};
  vector<char> letters = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
  vector<int> score = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};
  EXPECT_EQ(sol.maxScoreWords(words, letters, score), 27);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> words = {"leetcode"};
  vector<char> letters = {'l', 'e', 't', 'c', 'o', 'd'};
  vector<int> score = {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0,
                       0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
  EXPECT_EQ(sol.maxScoreWords(words, letters, score), 0);
}

