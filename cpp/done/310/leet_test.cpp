#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<int>> edges{ { 1, 0 }, { 1, 2 }, { 1, 3 } };
  vector<int> expect{ 1 };

  EXPECT_EQ(sol.findMinHeightTrees(4, edges), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<int>> edges{ { 0, 3 }, { 1, 3 }, { 2, 3 }, { 4, 3 }, { 5, 4 } };
  vector<int> expect{ 3, 4 };

  EXPECT_EQ(sol.findMinHeightTrees(6, edges), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<vector<int>> edges;
  vector<int> expect;

  EXPECT_EQ(sol.findMinHeightTrees(0, edges), expect);
}

TEST(kk, t4)
{
  Solution sol;
  vector<vector<int>> edges;
  vector<int> expect{ 0 };

  EXPECT_EQ(sol.findMinHeightTrees(1, edges), expect);
}

TEST(kk, t5)
{
  Solution sol;
  vector<vector<int>> edges{ { 0, 1 }, { 0, 2 }, { 0, 3 }, { 3, 4 }, { 4, 5 } };
  vector<int> expect{ 3 };

  EXPECT_EQ(sol.findMinHeightTrees(6, edges), expect);
}

