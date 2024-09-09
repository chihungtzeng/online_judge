#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> grid{{1, 1, 1, -1, -1},
                           {1, 1, 1, -1, -1},
                           {-1, -1, -1, 1, 1},
                           {1, 1, 1, 1, -1},
                           {-1, -1, -1, -1, -1}};
  vector<int> expect{1, -1, -1, -1, -1};

  EXPECT_EQ(sol.findBall(grid), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> grid{{-1}};
  vector<int> expect{-1};

  EXPECT_EQ(sol.findBall(grid), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> grid{{1}};
  vector<int> expect{-1};

  EXPECT_EQ(sol.findBall(grid), expect);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<int>> grid{
      {1,  -1, -1, 1,  -1, 1,  1,  1,  1,  1,  -1, 1,  1,  1,
       1,  1,  1,  -1, -1, -1, -1, -1, -1, 1,  -1, 1,  -1, 1,
       -1, -1, -1, -1, 1,  -1, 1,  1,  -1, -1, -1, -1, -1, 1},
      {-1, 1,  1,  1,  -1, -1, -1, -1, 1,  1,  1, -1, -1, -1,
       1,  -1, -1, 1,  1,  1,  1,  1,  1,  -1, 1, -1, -1, -1,
       -1, -1, 1,  -1, 1,  -1, -1, -1, -1, 1,  1, -1, 1,  1},
      {1,  -1, -1, -1, -1, 1, -1, 1,  1,  1,  1, 1,  1, 1,
       -1, 1,  -1, -1, -1, 1, -1, -1, 1,  -1, 1, -1, 1, -1,
       -1, 1,  -1, 1,  -1, 1, 1,  -1, -1, 1,  1, -1, 1, -1}};
  vector<int> expect{-1, -1, 1,  -1, -1, -1, -1, 10, 11, -1, -1, 12, 13, -1,
                     -1, -1, -1, -1, 17, -1, -1, 20, -1, -1, -1, -1, -1, -1,
                     -1, -1, 27, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

  EXPECT_EQ(sol.findBall(grid), expect);
}

