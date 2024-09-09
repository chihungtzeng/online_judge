#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int candies = 7, num_people = 4;
  vector<int> expect{1, 2, 3, 1};
  EXPECT_EQ(sol.distributeCandies(candies, num_people), expect);
}

TEST(kk, t2) {
  Solution sol;
  int candies = 10, num_people = 3;
  vector<int> expect{5, 2, 3};
  EXPECT_EQ(sol.distributeCandies(candies, num_people), expect);
}

TEST(kk, t3) {
  Solution sol;
  int candies = 1e9, num_people = 13;
  vector<int> expect{76937920, 76902920, 76906360, 76909800, 76913240,
                     76916680, 76920120, 76923560, 76927000, 76930440,
                     76933880, 76937320, 76940760};
  EXPECT_EQ(sol.distributeCandies(candies, num_people), expect);
}

TEST(kk, t4) {
  Solution sol;
  int candies = 2, num_people = 3;
  vector<int> expect{1, 1, 0};
  EXPECT_EQ(sol.distributeCandies(candies, num_people), expect);
}

TEST(kk, t5) {
  Solution sol;
  int candies = 1e9, num_people = 1;
  vector<int> expect{(int)1e9};
  EXPECT_EQ(sol.distributeCandies(candies, num_people), expect);
}

