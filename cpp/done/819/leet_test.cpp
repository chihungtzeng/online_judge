#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
  vector<string> banned = {"hit"};

  EXPECT_EQ(sol.mostCommonWord(paragraph, banned), "ball");
}

