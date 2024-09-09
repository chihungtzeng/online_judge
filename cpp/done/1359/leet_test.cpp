#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countOrders(1), 1);
  EXPECT_EQ(sol.countOrders(2), 6);
  EXPECT_EQ(sol.countOrders(3), 90);
  EXPECT_EQ(sol.countOrders(4), 2520);
  EXPECT_EQ(sol.countOrders(500), 764678010);
}

