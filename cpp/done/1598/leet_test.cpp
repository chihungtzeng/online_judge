#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
  EXPECT_EQ(sol.minOperations(logs), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> logs = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
  EXPECT_EQ(sol.minOperations(logs), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> logs = {"d1/", "../", "../", "../"};
  EXPECT_EQ(sol.minOperations(logs), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<string> logs = {"./", "../", "./"};
  EXPECT_EQ(sol.minOperations(logs), 0);
}

