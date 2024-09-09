#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numberOfSubstrings("abcabc"), 10);
  EXPECT_EQ(sol.numberOfSubstrings("aaacb"), 3);
  EXPECT_EQ(sol.numberOfSubstrings("abc"), 1);
  EXPECT_EQ(sol.numberOfSubstrings("aaacbbccabcaabcabcbbbac"), 211);
}

