#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
  int n = 5;
  vector<int> expect{10, 55, 45, 25, 25};
  EXPECT_EQ(sol.corpFlightBookings(bookings, n), expect);
}

