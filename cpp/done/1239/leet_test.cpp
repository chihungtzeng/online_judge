#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> arr = {"un", "iq", "ue"};
  EXPECT_EQ(sol.maxLength(arr), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> arr = {"cha", "r", "act", "ers"};
  EXPECT_EQ(sol.maxLength(arr), 6);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> arr = {"abcdefghijklmnopqrstuvwxyz"};
  EXPECT_EQ(sol.maxLength(arr), 26);
}

TEST(kk, t4) {
  Solution sol;
  vector<string> arr = {"yy", "bkhwmpbiisbldzknpm"};
  EXPECT_EQ(sol.maxLength(arr), 0);
}

