#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<char>> grid = {
      {'#', '#', '#', '#', '#', '#'},
      {'#', 'T', '#', '#', '#', '#'},
      {'#', '.', '.', 'B', '.', '#'},
      {'#', '.', '#', '#', '.', '#'},
      {'#', '.', '.', '.', 'S', '#'},
      {'#', '#', '#', '#', '#', '#'}};
  EXPECT_EQ(sol.minPushBox(grid), 3);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<char>> grid = {
      {'#', '#', '#', '#', '#', '#'}, {'#', 'T', '#', '#', '#', '#'},
      {'#', '.', '.', 'B', '.', '#'}, {'#', '#', '#', '#', '.', '#'},
      {'#', '.', '.', '.', 'S', '#'}, {'#', '#', '#', '#', '#', '#'}};
  EXPECT_EQ(sol.minPushBox(grid), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<char>> grid = {
      {'#', '#', '#', '#', '#', '#'}, {'#', 'T', '.', '.', '#', '#'},
      {'#', '.', '#', 'B', '.', '#'}, {'#', '.', '.', '.', '.', '#'},
      {'#', '.', '.', '.', 'S', '#'}, {'#', '#', '#', '#', '#', '#'}};
  EXPECT_EQ(sol.minPushBox(grid), 5);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<char>> grid = {{'#', '#', '#', '#', '#', '#', '#'},
                               {'#', 'S', '#', '.', 'B', 'T', '#'},
                               {'#', '#', '#', '#', '#', '#', '#'}};
  EXPECT_EQ(sol.minPushBox(grid), -1);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<char>> grid = {{'#', '.', '.', '#', 'T', '#', '#', '#', '#'},
                               {'#', '.', '.', '#', '.', '#', '.', '.', '#'},
                               {'#', '.', '.', '#', '.', '#', 'B', '.', '#'},
                               {'#', '.', '.', '.', '.', '.', '.', '.', '#'},
                               {'#', '.', '.', '.', '.', '#', '.', 'S', '#'},
                               {'#', '.', '.', '#', '.', '#', '#', '#', '#'}};

  EXPECT_EQ(sol.minPushBox(grid), 8);
}

TEST(kk, t6) {
  Solution sol;
  vector<vector<char>> grid = {{'#', '#', 'T', '#', '#', '#'},
                               {'.', '.', '.', '.', 'B', 'S'},
                               {'.', '.', '.', '#', '#', '#'}};
  EXPECT_EQ(sol.minPushBox(grid), 5);
}

