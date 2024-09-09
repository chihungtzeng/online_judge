#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string S = "a1b2";
  vector<string> expect{"a1b2", "a1B2", "A1b2", "A1B2"};
  auto actual = sol.letterCasePermutation(S);
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t2) {
  Solution sol;
  string S = "3z4";
  vector<string> expect{"3z4", "3Z4"};
  auto actual = sol.letterCasePermutation(S);
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t3) {
  Solution sol;
  string S = "12345";
  vector<string> expect{"12345"};
  auto actual = sol.letterCasePermutation(S);
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual, expect);
}


