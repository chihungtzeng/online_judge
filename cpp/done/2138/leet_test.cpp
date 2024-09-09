#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string s = "abcdefghi"; int k = 3; char fill = 'x';
  vector<string> expect{"abc","def","ghi"};
  EXPECT_EQ(sol.divideString(s, k, fill), expect);
}

TEST(kk, t2) {
  Solution sol;
  string s = "abcdefghij"; int k = 3; char fill = 'x';
  vector<string> expect{"abc","def","ghi","jxx"};
  EXPECT_EQ(sol.divideString(s, k, fill), expect);
}

TEST(kk, t3) {
  Solution sol;
  string s = "abc"; int k = 1; char fill = 'x';
  vector<string> expect{"a","b","c"};

  EXPECT_EQ(sol.divideString(s, k, fill), expect);
}

