#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string bottom = "BCD";
  vector<string> allowed {"BCG", "CDE", "GEA", "FFF"};

  EXPECT_EQ(sol.pyramidTransition(bottom, allowed), true);
}

TEST(kk, t2) {
  Solution sol;
  string bottom = "AABA";
  vector<string> allowed{"AAA", "AAB", "ABA", "ABB", "BAC"};

  EXPECT_EQ(sol.pyramidTransition(bottom, allowed), false);
}

