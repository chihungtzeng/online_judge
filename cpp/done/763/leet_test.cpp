#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> expect{9,7,8};

  EXPECT_EQ(sol.partitionLabels("ababcbacadefegdehijhklij"), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> expect{3,2,1};

  EXPECT_EQ(sol.partitionLabels("abaccd"), expect);
}

