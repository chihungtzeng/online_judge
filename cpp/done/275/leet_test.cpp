#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  std::vector<int> citations{3,0,6,1,5};
  std::sort(citations.begin(), citations.end());

  EXPECT_EQ(sol.hIndex(citations), 3);
}

TEST(kk, t2) {
  Solution sol;
  std::vector<int> citations{10,10,10,10};

  EXPECT_EQ(sol.hIndex(citations), 4);
}

TEST(kk, t3) {
  Solution sol;
  std::vector<int> citations;

  EXPECT_EQ(sol.hIndex(citations), 0);
}

TEST(kk, t4) {
  Solution sol;
  std::vector<int> citations{12345};

  EXPECT_EQ(sol.hIndex(citations), 1);
}

