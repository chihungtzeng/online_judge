#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  string s = "abpcplea";
  vector<string> d{ "ale", "apple", "monkey", "plea" };

  EXPECT_EQ(sol.findLongestWord(s, d), "apple");
}

TEST(kk, t2)
{
  Solution sol;
  string s = "abpcplea";
  vector<string> d{ "p", "a", "b", "c" };

  EXPECT_EQ(sol.findLongestWord(s, d), "a");
}

