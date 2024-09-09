#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<string> expect{"1/2","1/3","1/4","2/3","3/4"};
  auto actual = sol.simplifiedFractions(4);
  sort(actual.begin(), actual.end());
  sort(expect.begin(), expect.end());
  EXPECT_EQ(actual , expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> expect;
  EXPECT_EQ(sol.simplifiedFractions(1), expect);
}

