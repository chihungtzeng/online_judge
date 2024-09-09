#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> expect{"e", "f", "ccc"};
  sort(expect.begin(), expect.end());
  auto actual = sol.maxNumOfSubstrings("adefaddaccc");
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> expect{"d", "bb", "cc"};
  sort(expect.begin(), expect.end());
  auto actual = sol.maxNumOfSubstrings("abbaccd");
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> expect{"ababa"};
  sort(expect.begin(), expect.end());
  auto actual = sol.maxNumOfSubstrings("ababa");
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

