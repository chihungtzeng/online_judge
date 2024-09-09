#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<char>> box = {{'#', '.', '#'}};
  vector<vector<char>> expect{{'.'}, {'#'}, {'#'}};
  EXPECT_EQ(sol.rotateTheBox(box), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<char>> box = {{'#', '.', '*', '.'}, {'#', '#', '*', '.'}};
  vector<vector<char>> expect{{'#', '.'}, {'#', '#'}, {'*', '*'}, {'.', '.'}};
  EXPECT_EQ(sol.rotateTheBox(box), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<char>> box = {{'#', '#', '*', '.', '*', '.'},
                              {'#', '#', '#', '*', '.', '.'},
                              {'#', '#', '#', '.', '#', '.'}};
  vector<vector<char>> expect{{'.', '#', '#'}, {'.', '#', '#'},
                              {'#', '#', '*'}, {'#', '*', '.'},
                              {'#', '.', '*'}, {'#', '.', '.'}};
  EXPECT_EQ(sol.rotateTheBox(box), expect);
}

