#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> ghosts{{1, 0}, {0, 3}};
  vector<int> target{0, 1};

  EXPECT_EQ(sol.escapeGhosts(ghosts, target), true);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> ghosts{{1, 0}};
  vector<int> target{2, 0};

  EXPECT_EQ(sol.escapeGhosts(ghosts, target), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> ghosts{{2, 0}};
  vector<int> target{1, 0};

  EXPECT_EQ(sol.escapeGhosts(ghosts, target), false);
}

