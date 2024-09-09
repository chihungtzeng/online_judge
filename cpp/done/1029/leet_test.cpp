#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> costs = {{10,20},{30,200},{400,50},{30,20}};
  EXPECT_EQ(sol.twoCitySchedCost(costs), 110);
}


TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> costs = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
  EXPECT_EQ(sol.twoCitySchedCost(costs), 1859);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> costs = {{515,563},{451,713},{537,709},{343,819},{855,779},{457,60},{650,359},{631,42}};
  EXPECT_EQ(sol.twoCitySchedCost(costs), 3086);
}

