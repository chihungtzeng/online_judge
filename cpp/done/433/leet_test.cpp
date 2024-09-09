#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> bank{"AACCGGTA"};
  EXPECT_EQ(sol.minMutation("AACCGGTT", "AACCGGTA", bank), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> bank{"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  EXPECT_EQ(sol.minMutation("AACCGGTT", "AAACGGTA", bank), 2);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> bank{"AAAACCCC", "AAACCCCC", "AACCCCCC"};
  EXPECT_EQ(sol.minMutation("AAAAACCC", "AACCCCCC", bank), 3);
}

