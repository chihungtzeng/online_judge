#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
  string target = "0202";

  EXPECT_EQ(sol.openLock(deadends, target), 6);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> deadends{"8888"};
  string target = "0009";

  EXPECT_EQ(sol.openLock(deadends, target), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<string> deadends{"8887", "8889", "8878", "8898",
                          "8788", "8988", "7888", "9888"};
  string target = "8888";

  EXPECT_EQ(sol.openLock(deadends, target), -1);
}

TEST(kk, t4) {
  Solution sol;
  vector<string> deadends{"0000"};
  string target = "8888";

  EXPECT_EQ(sol.openLock(deadends, target), -1);
}

