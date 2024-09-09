#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.dayOfYear("2019-01-09"), 9);
  EXPECT_EQ(sol.dayOfYear("2019-02-10"), 41);
  EXPECT_EQ(sol.dayOfYear("2003-03-01"), 60);
  EXPECT_EQ(sol.dayOfYear("2004-03-01"), 61);
  EXPECT_EQ(sol.dayOfYear("2000-03-01"), 61);
  EXPECT_EQ(sol.dayOfYear("1900-03-01"), 60);
}

