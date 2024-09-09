#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> expect{3,2,0,1};
  EXPECT_EQ(sol.circularPermutation(2, 3), expect);
}

