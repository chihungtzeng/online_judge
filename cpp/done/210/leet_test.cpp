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
  vector<int> expect{ 0, 1 };
  EXPECT_EQ(sol.findOrder(numCourses, prerequisites), expect);
}

TEST(kk, t2)
{
  Solution sol;
  int numCourses = 4;
  vector<vector<int>> prerequisites = { { 1, 0 }, { 2, 0 }, { 3, 1 }, { 3, 2 } };
  vector<int> expect{ 0, 2, 1, 3 };
  EXPECT_EQ(sol.findOrder(numCourses, prerequisites), expect);
}

