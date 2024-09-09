#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1},
                               {1, 1}, {1, 1}, {1, 2}};
  int shelf_width = 4;
  EXPECT_EQ(sol.minHeightShelves(books, shelf_width), 6);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> books = {{1,3},{2,4},{3,2}};
  int shelf_width = 6;
  EXPECT_EQ(sol.minHeightShelves(books, shelf_width), 4);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> books = {{7,3},{8,7},{2,7},{2,5}};
  int shelf_width = 10;
  EXPECT_EQ(sol.minHeightShelves(books, shelf_width), 15);
}

