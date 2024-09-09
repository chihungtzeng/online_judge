#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> votes = {"ABC", "ACB", "ABC", "ACB", "ACB"};
  EXPECT_EQ(sol.rankTeams(votes), "ACB");
}

#if 1
TEST(kk, t2) {
  Solution sol;
  vector<string> votes = {"WXYZ", "XYZW"};
  EXPECT_EQ(sol.rankTeams(votes), "XWYZ");
}

TEST(kk, t3) {
  Solution sol;
  vector<string> votes = {"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
  EXPECT_EQ(sol.rankTeams(votes), "ZMNAGUEDSJYLBOPHRQICWFXTVK");
}

TEST(kk, t4) {
  Solution sol;
  vector<string> votes = {"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"};
  EXPECT_EQ(sol.rankTeams(votes), "ABC");
}

TEST(kk, t5) {
  Solution sol;
  vector<string> votes = {"M", "M", "M", "M"};
  EXPECT_EQ(sol.rankTeams(votes), "M");
}

#endif
