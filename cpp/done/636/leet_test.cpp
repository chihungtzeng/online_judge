#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 2;
  vector<string> logs{"0:start:0","1:start:2","1:end:5","0:end:6"};
  vector<int> expect{3,4};

  EXPECT_EQ(sol.exclusiveTime(n, logs), expect);
}

TEST(kk, t2) {
  Solution sol;
  int n = 3;
  vector<string> logs{"0:start:0","1:start:3","1:end:4", "2:start:9","2:end:13", "0:end:20"};
  vector<int> expect{14,2,5};

  EXPECT_EQ(sol.exclusiveTime(n, logs), expect);
}

