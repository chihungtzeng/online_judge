#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<char>> board{
      {'X', '.', '.', 'X'},
      {'.', '.', '.', 'X'},
      {'.', '.', '.', 'X'}};

  EXPECT_EQ(sol.countBattleships(board), 2);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<char>> board{
      {'X', '.', '.', 'X'},
      {'.', '.', '.', 'X'},
      {'X', 'X', '.', 'X'}};

  EXPECT_EQ(sol.countBattleships(board), 3);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<char>> board;

  EXPECT_EQ(sol.countBattleships(board), 0);
}

TEST(kk, t3_1) {
  Solution sol;
  vector<vector<char>> board(5);

  EXPECT_EQ(sol.countBattleships(board), 0);
}

TEST(kk, t4) {
  Solution sol;
  vector<vector<char>> board{{'X'}};

  EXPECT_EQ(sol.countBattleships(board), 1);
}

TEST(kk, t5) {
  Solution sol;
  vector<vector<char>> board{{'.'}};

  EXPECT_EQ(sol.countBattleships(board), 0);
}

