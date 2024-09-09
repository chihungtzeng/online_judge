#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t0) {
  Solution sol;

  string s = "2-1-1";
  std::vector<int> expect{0, 2};
  std::sort(expect.begin(), expect.end());
  auto actual = sol.diffWaysToCompute(s);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

TEST(kk, t1) {
  Solution sol;

  string s = "2*3-4*5";
  std::vector<int> expect{-34, -14, -10, -10, 10};
  std::sort(expect.begin(), expect.end());
  auto actual = sol.diffWaysToCompute(s);
  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
}

