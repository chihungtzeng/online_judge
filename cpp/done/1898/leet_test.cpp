#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;

  string s = "abcacb", p = "ab";
  vector<int> removable = {3, 1, 0};
  EXPECT_EQ(sol.maximumRemovals(s, p, removable), 2);
}

TEST(kk, t2) {
  Solution sol;
  string s = "abcbddddd", p = "abcd";
  vector<int> removable = {3, 2, 1, 4, 5, 6};
  EXPECT_EQ(sol.maximumRemovals(s, p, removable), 1);
}

TEST(kk, t3) {
  Solution sol;
  string s = "abcab", p = "abc";
  vector<int> removable = {0, 1, 2, 3, 4};
  EXPECT_EQ(sol.maximumRemovals(s, p, removable), 0);
}

TEST(kk, t4) {
  Solution sol;
  string s = "qlevcvgzfpryiqlwy", p = "qlecfqlw";
  vector<int> removable = {12,5};
  EXPECT_EQ(sol.maximumRemovals(s, p, removable), 2);
}
