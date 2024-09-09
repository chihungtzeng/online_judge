#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> status = {1, 0, 1, 0}, candies = {7, 5, 4, 100};
  vector<vector<int>> keys = {{}, {}, {1}, {}},
                      containedBoxes = {{1, 2}, {3}, {}, {}};
  vector<int> initialBoxes = {0};
  EXPECT_EQ(sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes),
            16);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> status = {1, 0, 0, 0, 0, 0}, candies = {1, 1, 1, 1, 1, 1};
  vector<vector<int>> keys = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}},
                      containedBoxes = {{1, 2, 3, 4, 5}, {}, {}, {}, {}, {}};
  vector<int> initialBoxes = {0};
  EXPECT_EQ(sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes),
            6);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> status = {1, 1, 1}, candies = {100, 1, 100};
  vector<vector<int>> keys = {{}, {0, 2}, {}}, containedBoxes = {{}, {}, {}};
  vector<int> initialBoxes = {1};
  EXPECT_EQ(sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes),
            1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> status = {1}, candies = {100};
  vector<vector<int>> keys = {{}}, containedBoxes = {{}};
  vector<int> initialBoxes = {};
  EXPECT_EQ(sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes),
            0);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> status = {1, 1, 1}, candies = {2, 3, 2};
  vector<vector<int>> keys = {{}, {}, {}}, containedBoxes = {{}, {}, {}};
  vector<int> initialBoxes = {2, 1, 0};
  EXPECT_EQ(sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes),
            7);
}

