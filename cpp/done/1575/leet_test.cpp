#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> locations = {2,3,6,8,4};
  int start = 1, finish = 3, fuel = 5;

  EXPECT_EQ(sol.countRoutes(locations, start, finish, fuel), 4);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> locations = {1,2,3};
  int start = 0, finish = 2, fuel = 40;

  EXPECT_EQ(sol.countRoutes(locations, start, finish, fuel), 615088286);
}

