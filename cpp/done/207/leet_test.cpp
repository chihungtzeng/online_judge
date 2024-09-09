#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  int numCourses = 2;
  vector<vector<int>> prerequisites = { { 1, 0 } };
  EXPECT_EQ(sol.canFinish(numCourses, prerequisites), true);
}

TEST(kk, t2)
{
  Solution sol;
  int numCourses = 2;
  vector<vector<int>> prerequisites = { { 1, 0 }, { 0, 1 } };
  EXPECT_EQ(sol.canFinish(numCourses, prerequisites), false);
}

