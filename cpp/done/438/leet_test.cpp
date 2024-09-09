#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> expect{0,6};
  EXPECT_EQ(sol.findAnagrams("cbaebabacd", "abc"), expect);

  vector<int> expect2{0,1,2};
  EXPECT_EQ(sol.findAnagrams("abab", "ab"), expect2);
}

