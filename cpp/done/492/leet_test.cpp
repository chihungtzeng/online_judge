#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> expect{2, 2};
  EXPECT_EQ(sol.constructRectangle(4), expect);
  vector<int> expect5{5, 1};
  EXPECT_EQ(sol.constructRectangle(5), expect5);
  vector<int> expect6{3, 2};
  EXPECT_EQ(sol.constructRectangle(6), expect6);
  vector<int> expect97{97, 11};
  EXPECT_EQ(sol.constructRectangle(97 * 11), expect97);
  vector<int> expect10{10, 10};
  EXPECT_EQ(sol.constructRectangle(100), expect10);

  vector<int> expect197{97, 1};
  EXPECT_EQ(sol.constructRectangle(97), expect197);

  vector<int> expect3200{3200, 3125};
  EXPECT_EQ(sol.constructRectangle(10000000), expect3200);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> expect18{6, 3};
  EXPECT_EQ(sol.constructRectangle(18), expect18);
}
