#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.isTransformable("84532", "34852"), true);
  EXPECT_EQ(sol.isTransformable("34521", "23415"), true);
  EXPECT_EQ(sol.isTransformable("12345",  "12435"), false);
  EXPECT_EQ(sol.isTransformable("1", "2"), false);
}

