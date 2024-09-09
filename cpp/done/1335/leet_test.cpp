#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> jobDifficulty = {6,5,4,3,2,1}; int d = 2;
  EXPECT_EQ(sol.minDifficulty(jobDifficulty, d), 7);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> jobDifficulty = {9,9,9}; int d = 4;
  EXPECT_EQ(sol.minDifficulty(jobDifficulty, d), -1);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> jobDifficulty = {1,1,1}; int d = 3;
  EXPECT_EQ(sol.minDifficulty(jobDifficulty, d), 3);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> jobDifficulty = {7,1,7,1,7,1}; int d = 3;
  EXPECT_EQ(sol.minDifficulty(jobDifficulty, d), 15);
}

TEST(kk, t5) {
  Solution sol;
  vector<int> jobDifficulty = {11,111,22,222,33,333,44,444}; int d = 6;
  EXPECT_EQ(sol.minDifficulty(jobDifficulty, d), 843);
}

