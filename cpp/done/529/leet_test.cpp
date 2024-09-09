#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  vector<vector<char>> board = {
    { 'E', 'E', 'E', 'E', 'E' }, { 'E', 'E', 'M', 'E', 'E' }, { 'E', 'E', 'E', 'E', 'E' }, { 'E', 'E', 'E', 'E', 'E' }
  };
  vector<int> click = { 3, 0 };
  vector<vector<char>> expect{
    { 'B', '1', 'E', '1', 'B' }, { 'B', '1', 'M', '1', 'B' }, { 'B', '1', '1', '1', 'B' }, { 'B', 'B', 'B', 'B', 'B' }
  };
  EXPECT_EQ(sol.updateBoard(board, click), expect);
}

TEST(kk, t2)
{
  Solution sol;
  vector<vector<char>> board = {
    { 'B', '1', 'E', '1', 'B' }, { 'B', '1', 'M', '1', 'B' }, { 'B', '1', '1', '1', 'B' }, { 'B', 'B', 'B', 'B', 'B' }
  };
  vector<int> click = { 1, 2 };
  vector<vector<char>> expect{
    { 'B', '1', 'E', '1', 'B' }, { 'B', '1', 'X', '1', 'B' }, { 'B', '1', '1', '1', 'B' }, { 'B', 'B', 'B', 'B', 'B' }
  };
  EXPECT_EQ(sol.updateBoard(board, click), expect);
}

TEST(kk, t3)
{
  Solution sol;
  vector<vector<char>> board{ { 'E', 'M', 'M', '2', 'B', 'B', 'B', 'B' }, { 'E', 'E', 'M', '2', 'B', 'B', 'B', 'B' },
                              { 'E', 'E', '2', '1', 'B', 'B', 'B', 'B' }, { 'E', 'M', '1', 'B', 'B', 'B', 'B', 'B' },
                              { '1', '2', '2', '1', 'B', 'B', 'B', 'B' }, { 'B', '1', 'M', '1', 'B', 'B', 'B', 'B' },
                              { 'B', '1', '1', '1', 'B', 'B', 'B', 'B' }, { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' } };

  vector<int> click = { 0, 0 };
  vector<vector<char>> expect{ { '1', 'M', 'M', '2', 'B', 'B', 'B', 'B' }, { 'E', 'E', 'M', '2', 'B', 'B', 'B', 'B' },
                               { 'E', 'E', '2', '1', 'B', 'B', 'B', 'B' }, { 'E', 'M', '1', 'B', 'B', 'B', 'B', 'B' },
                               { '1', '2', '2', '1', 'B', 'B', 'B', 'B' }, { 'B', '1', 'M', '1', 'B', 'B', 'B', 'B' },
                               { 'B', '1', '1', '1', 'B', 'B', 'B', 'B' }, { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' } };

  EXPECT_EQ(sol.updateBoard(board, click), expect);
}

