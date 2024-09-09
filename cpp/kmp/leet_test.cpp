#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {

  vector<int> expect{0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5};
  EXPECT_EQ(lps_of("AABAACAABAA"), expect);

  expect = {0, 1, 2, 0, 1, 2, 3, 3, 3, 4};
  EXPECT_EQ(lps_of("AAACAAAAAC"), expect);

  expect = {0, 1, 2, 0, 1, 2, 3};
  EXPECT_EQ(lps_of("AAABAAA"), expect);

  expect = {0, 0, 0, 0, 0};
  EXPECT_EQ(lps_of("ABCDE"), expect);

  expect = {0, 1, 2, 3};
  EXPECT_EQ(lps_of("AAAA"), expect);
}

TEST(kk, t2) {
  string haystack = "AABAACAADAABAABA";
  string needle = "AABA";
  vector<int> expect{0, 9, 12};
  EXPECT_EQ(str_match(haystack, needle), expect);


  haystack = "aa";
  needle = "a";
  expect = {0, 1};
  EXPECT_EQ(str_match(haystack, needle), expect);
}

TEST(kk, t3) {
  string haystack = "cdabcdab";
  string needle = "abcd";
  LOG(INFO) << str_match(haystack, needle);
}

TEST(kk, t4) {
  string haystack = "aabaaabaaac";
  string needle = "aabaaac";
  vector<int> expect{4};
  EXPECT_EQ(str_match(haystack, needle), expect);
}


