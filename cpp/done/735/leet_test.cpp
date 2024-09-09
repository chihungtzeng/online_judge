#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> asteroids{5, 10, -5};
  vector<int> expect{5, 10};
  EXPECT_EQ(sol.asteroidCollision(asteroids), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> asteroids{8, -8};
  vector<int> expect;
  EXPECT_EQ(sol.asteroidCollision(asteroids), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> asteroids{10, 2, -5};
  vector<int> expect{10};
  EXPECT_EQ(sol.asteroidCollision(asteroids), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> asteroids{-2, -1, 1, 2};
  vector<int> expect{-2, -1, 1, 2};
  EXPECT_EQ(sol.asteroidCollision(asteroids), expect);
}

