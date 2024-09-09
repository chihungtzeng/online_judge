#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> org = {1, 2, 3};
  vector<vector<int>> seqs = {{1, 2}, {1, 3}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), false);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> org = {1, 2, 3};
  vector<vector<int>> seqs = {{1, 2}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), false);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> org = {1, 2, 3};
  vector<vector<int>> seqs = {{1, 2}, {1, 3}, {2, 3}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), true);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> org = {4, 1, 5, 2, 6, 3};
  vector<vector<int>> seqs = {{5, 2, 6, 3}, {4, 1, 5, 2}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), true);
}

/*
TEST(kk, t5) {
  Solution sol;
  vector<int> org = {1};
  vector<vector<int>> seqs = {{}, {}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), false);
}
*/

TEST(kk, t6) {
  Solution sol;
  vector<int> org = {1};
  vector<vector<int>> seqs = {{2}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), false);
}

TEST(kk, t7) {
  Solution sol;
  vector<int> org = {5, 3, 2, 4, 1};
  vector<vector<int>> seqs = {{5, 3, 2, 4}, {4, 1}, {1},
                              {3},          {2, 4}, {1, 1000000000}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), false);
}

TEST(kk, t8) {
  Solution sol;
  vector<int> org = {1};
  vector<vector<int>> seqs = {{1, -9}, {-9, -8}, {-8, -9}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), false);
}

TEST(kk, t9) {
  Solution sol;
  vector<int> org = {1};
  vector<vector<int>> seqs = {{1}, {1}, {1}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), true);
}
TEST(kk, t10) {
  Solution sol;

  vector<int> org = {1};
  vector<vector<int>> seqs = {};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), false);
}
TEST(kk, t11) {
  Solution sol;

  vector<int> org = {1};
  vector<vector<int>> seqs = {{1}, {2, 3}, {3, 2}};
  EXPECT_EQ(sol.sequenceReconstruction(org, seqs), false);
}

