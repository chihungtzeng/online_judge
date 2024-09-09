#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  string n = "32";
  EXPECT_EQ(sol.minPartitions(n), 3);
}

TEST(kk, t2) {
  Solution sol;
  string n = "82734";
  EXPECT_EQ(sol.minPartitions(n), 8);
}

TEST(kk, t3) {
  Solution sol;
  string n = "27346209830709182346";
  EXPECT_EQ(sol.minPartitions(n), 9);
}

TEST(kk, t4) {
  Solution sol;
  string n = "2751182314";
  EXPECT_EQ(sol.minPartitions(n), 8);
}

