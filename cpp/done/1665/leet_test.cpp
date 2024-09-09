#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> tasks = {{1, 2}, {2, 4}, {4, 8}};
  EXPECT_EQ(sol.minimumEffort(tasks), 8);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> tasks = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
  EXPECT_EQ(sol.minimumEffort(tasks), 32);
}

TEST(kk, t3) {
  Solution sol;
  vector<vector<int>> tasks = {{1, 7},  {2, 8},  {3, 9},
                               {4, 10}, {5, 11}, {6, 12}};
  EXPECT_EQ(sol.minimumEffort(tasks), 27);
}

TEST(kk, t4) {
  Solution sol;
  srand(time(NULL));
  vector<vector<int>> tasks;
  for(int i=0; i<100000; i++){
    int energy = rand() % 100;
    int required = energy + rand() % 100;
    tasks.push_back(vector<int>{energy, required});
  }
  EXPECT_EQ(sol.minimumEffort(tasks), 27);
}

