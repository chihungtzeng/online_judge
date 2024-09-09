#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words{"wrt", "wrf", "er", "ett", "rftt"};
  EXPECT_EQ(sol.alienOrder(words), "wertf");
}

TEST(kk, t2) {
  Solution sol;

  vector<string> words{"z", "x"};
  EXPECT_EQ(sol.alienOrder(words), "zx");
}

TEST(kk, t2_1) {
  Solution sol;

  vector<string> words{"z", "z"};
  EXPECT_EQ(sol.alienOrder(words), "z");
}

TEST(kk, t3) {
  Solution sol;

  vector<string> words{"z", "x", "z"};
  EXPECT_EQ(sol.alienOrder(words), "");
}

TEST(kk, t4) {
  Solution sol;

  vector<string> words{"ab", "adc"};
  EXPECT_EQ(sol.alienOrder(words), "abcd");
}

TEST(kk, t5) {
  Solution sol;

  vector<string> words{"abc", "ab"};
  EXPECT_EQ(sol.alienOrder(words), "");
}

TEST(kk, t6) {
  Solution sol;

  vector<string> words{"za","zb","ca","cb"};
  EXPECT_EQ(sol.alienOrder(words).size(), 4);
}
