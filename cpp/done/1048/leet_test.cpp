#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> words{"a","b","ba","bca","bda","bdca"};
  EXPECT_EQ(sol.longestStrChain(words), 4);
}

