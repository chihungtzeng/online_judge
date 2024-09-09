#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> rooms = {{2, 2}, {1, 2}, {3, 2}},
                      queries = {{3, 1}, {3, 3}, {5, 2}};
  vector<int> expect{3, -1, 3};
  EXPECT_EQ(sol.closestRoom(rooms, queries), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> rooms = {{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}},
                      queries = {{2, 3}, {2, 4}, {2, 5}};
  vector<int> expect{2, 1, 3};
  EXPECT_EQ(sol.closestRoom(rooms, queries), expect);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> rooms = {{23, 22}, {6, 20},  {15, 6}, {22, 19}, {2, 10},
                               {21, 4},  {10, 18}, {16, 1}, {12, 7},  {5, 22}},
                      queries = {{12, 5},  {15, 15}, {21, 6}, {15, 1}, {23, 4},
                                 {15, 11}, {1, 24},  {3, 19}, {25, 8}, {18, 6}};

  vector<int> expect{12, 10, 22, 15, 23, 10, -1, 5, 23, 15};
  EXPECT_EQ(sol.closestRoom(rooms, queries), expect);
}

