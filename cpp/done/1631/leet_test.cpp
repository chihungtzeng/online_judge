#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  EXPECT_EQ(sol.minimumEffortPath(heights), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
  EXPECT_EQ(sol.minimumEffortPath(heights), 1);
}

TEST(kk, t2_1) {
  Solution sol;
  vector<vector<int>> heights = {{1, 3, 4, 7}};
  EXPECT_EQ(sol.minimumEffortPath(heights), 3);
}

TEST(kk, t2_2) {
  Solution sol;
  vector<vector<int>> heights = {{1}, {3}, {4}, {7}};
  EXPECT_EQ(sol.minimumEffortPath(heights), 3);
}

TEST(kk, t2_3) {
  Solution sol;
  vector<vector<int>> heights {{1,10,6,7,9,10,4,9}};

  EXPECT_EQ(sol.minimumEffortPath(heights), 9);
}




TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> heights = {{1, 2, 1, 1, 1},
                                 {1, 2, 1, 2, 1},
                                 {1, 2, 1, 2, 1},
                                 {1, 2, 1, 2, 1},
                                 {1, 1, 1, 2, 1}};
  EXPECT_EQ(sol.minimumEffortPath(heights), 0);
}

