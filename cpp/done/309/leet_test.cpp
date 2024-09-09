#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  std::vector<int> prices{1,2,3,0,2};
  EXPECT_EQ(sol.maxProfit(prices), 3);

  std::vector<int> prices2{};
  EXPECT_EQ(sol.maxProfit(prices2), 0);

  std::vector<int> prices3{1000};
  EXPECT_EQ(sol.maxProfit(prices3), 0);

  std::vector<int> prices4{1000,1005};
  EXPECT_EQ(sol.maxProfit(prices4), 5);

  std::vector<int> prices5{10,20,30};
  EXPECT_EQ(sol.maxProfit(prices5), 20);
}

TEST(kk, t2) {
  Solution sol;

  std::vector<int> prices{1,2,10,3,20};
  EXPECT_EQ(sol.maxProfit(prices), 19);
}

TEST(kk, t3) {
  Solution sol;

  std::vector<int> prices{3,1,4,1,5,9,2,6};
  EXPECT_EQ(sol.maxProfit(prices), 8);
}

TEST(kk, t4) {
  Solution sol;

  std::vector<int> prices{3,1,4,1,5,9,2,6,2,7,1,8,2,8};
  EXPECT_EQ(sol.maxProfit(prices), 19);
}


