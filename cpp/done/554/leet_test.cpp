#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> wall{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2},
                           {2, 4},       {3, 1, 2}, {1, 3, 1, 1}};

  EXPECT_EQ(sol.leastBricks(wall), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> wall{
      {1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {3, 1, 2}, {1, 3, 1, 1}};

  EXPECT_EQ(sol.leastBricks(wall), 1);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> wall{{1}, {1}, {1}};

  EXPECT_EQ(sol.leastBricks(wall), 3);
}

