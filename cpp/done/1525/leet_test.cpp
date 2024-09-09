#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.numSplits("aacaba"), 2);
  EXPECT_EQ(sol.numSplits("abcd"), 1);
  EXPECT_EQ(sol.numSplits("aaaaa"), 4);
  EXPECT_EQ(sol.numSplits("acbadbaada"), 2);
  EXPECT_EQ(sol.numSplits("z"), 0);
  EXPECT_EQ(sol.numSplits("ccbbcaacbaabaaaaabbccabacccba"), 21);


}

