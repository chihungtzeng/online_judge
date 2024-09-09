#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> prices{1, 3, 2, 8, 4, 9};
  vector<int> prices2{3,1,4,1,5,9,2,6};

  EXPECT_EQ(sol.maxProfit(prices, 2), 8);
  EXPECT_EQ(sol.maxProfit(prices2, 1), 12);
}


