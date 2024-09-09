#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.customSortString("cba", "abcd"), "cbad");
  EXPECT_EQ(sol.customSortString("kqep", "pekeq"), "kqeep");
  LOG(INFO) << string(3, 'z');

}

