#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_TRUE(sol.wordPattern("abba", "dog cat cat dog"));
  EXPECT_FALSE(sol.wordPattern("abbaa", "dog cat cat dog"));
  EXPECT_FALSE(sol.wordPattern("abb", "dog cat cat dog"));
  EXPECT_FALSE(sol.wordPattern("abba", "dog cat cat fish"));
  EXPECT_FALSE(sol.wordPattern("aaaa", "dog cat cat dog"));
  EXPECT_FALSE(sol.wordPattern("abba", "dog dog dog dog"));
  EXPECT_FALSE(sol.wordPattern("abc", "dog cat dog"));
}

