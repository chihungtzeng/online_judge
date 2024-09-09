#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words{"w","wo","wor","worl", "world"};

  EXPECT_EQ(sol.longestWord(words), "world");
}

TEST(kk, t2) {
  Solution sol;
  vector<string> words{"a", "banana", "app", "appl", "ap", "apply", "apple"};

  EXPECT_EQ(sol.longestWord(words), "apple");
}

TEST(kk, t3) {
  Solution sol;
  vector<string> words{"a"};

  EXPECT_EQ(sol.longestWord(words), "a");
}

