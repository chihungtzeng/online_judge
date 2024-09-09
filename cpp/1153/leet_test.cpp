#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  string str1 = "aabcc", str2 = "ccdee";
  EXPECT_EQ(sol.canConvert(str1, str2), true);
}

TEST(kk, t2) {
  Solution sol;
  string str1 = "leetcode", str2 = "codeleet";
  EXPECT_EQ(sol.canConvert(str1, str2), false);
}

TEST(kk, t3) {
  Solution sol;
  string str1 = "abcdefghijklmnopqrstuvwxyz",
         str2 = "bcdefghijklmnopqrstuvwxyza";
  EXPECT_EQ(sol.canConvert(str1, str2), false);
  EXPECT_EQ(sol.canConvert(str1, str1), true);
}

TEST(kk, t4) {
  Solution sol;
  string str1 = "abcdefghijklmnopqrstuvwxyz",
         str2 = "bcdefghijklmnopqrstuvwxyzq";

  EXPECT_EQ(sol.canConvert(str1, str2), true);
}

TEST(kk, t5) {
  Solution sol;
  string str1 = "abcdefghijklmnopqrstuvwxy", str2 = "bcdefghijkamnopqrstuvwxyz";

  EXPECT_EQ(sol.canConvert(str1, str2), true);
}

TEST(kk, t6) {
  Solution sol;
  string str1 = "abcdefghijklmnopqrstuvwxyz";
  string str2 = "abcdefghijklmnopqrstuvwxzy";

  EXPECT_EQ(sol.canConvert(str1, str2), false);
}

