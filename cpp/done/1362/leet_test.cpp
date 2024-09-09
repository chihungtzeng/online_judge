#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  LOG(INFO) << sol.closestDivisors(8);
  LOG(INFO) << sol.closestDivisors(123);
  LOG(INFO) << sol.closestDivisors(999);
  LOG(INFO) << sol.closestDivisors(1000000000);
  vector<int> expect1{1,2};
  EXPECT_EQ(sol.closestDivisors(1), expect1);
  vector<int> expect2{2,2};
  EXPECT_EQ(sol.closestDivisors(2), expect2);
}

