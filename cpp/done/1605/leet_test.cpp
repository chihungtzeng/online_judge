#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> rowSum = {3, 8}, colSum = {4, 7};
  auto org_rowSum = rowSum;
  auto org_colSum = colSum;
  int r = rowSum.size();
  int c = colSum.size();
  auto ans = sol.restoreMatrix(rowSum, colSum);
  for (int i = 0; i < r; i++) {
    int s = accumulate(ans[i].begin(), ans[i].end(), 0);
    EXPECT_EQ(s, org_rowSum[i]);
  }
  for (int i = 0; i < c; i++) {
    int s = 0;
    for (int j = 0; j < r; j++) {
      s += ans[j][i];
    }
    EXPECT_EQ(s, org_colSum[i]);
  }
}

TEST(kk, t2) {
  Solution sol;
  vector<int> rowSum = {5, 7, 10}, colSum = {8, 6, 8};
  auto org_rowSum = rowSum;
  auto org_colSum = colSum;
  int r = rowSum.size();
  int c = colSum.size();
  auto ans = sol.restoreMatrix(rowSum, colSum);
  for (int i = 0; i < r; i++) {
    int s = accumulate(ans[i].begin(), ans[i].end(), 0);
    EXPECT_EQ(s, org_rowSum[i]);
  }
  for (int i = 0; i < c; i++) {
    int s = 0;
    for (int j = 0; j < r; j++) {
      s += ans[j][i];
    }
    EXPECT_EQ(s, org_colSum[i]);
  }
}
TEST(kk, t3) {
  Solution sol;
  vector<int> rowSum = {14, 9}, colSum = {6, 9, 8};

  auto org_rowSum = rowSum;
  auto org_colSum = colSum;
  int r = rowSum.size();
  int c = colSum.size();
  auto ans = sol.restoreMatrix(rowSum, colSum);
  for (int i = 0; i < r; i++) {
    int s = accumulate(ans[i].begin(), ans[i].end(), 0);
    EXPECT_EQ(s, org_rowSum[i]);
  }
  for (int i = 0; i < c; i++) {
    int s = 0;
    for (int j = 0; j < r; j++) {
      s += ans[j][i];
    }
    EXPECT_EQ(s, org_colSum[i]);
  }
}

TEST(kk, t4) {
  Solution sol;
  vector<int> rowSum = {1, 0}, colSum = {1};

  auto org_rowSum = rowSum;
  auto org_colSum = colSum;
  int r = rowSum.size();
  int c = colSum.size();
  auto ans = sol.restoreMatrix(rowSum, colSum);
  for (int i = 0; i < r; i++) {
    int s = accumulate(ans[i].begin(), ans[i].end(), 0);
    EXPECT_EQ(s, org_rowSum[i]);
  }
  for (int i = 0; i < c; i++) {
    int s = 0;
    for (int j = 0; j < r; j++) {
      s += ans[j][i];
    }
    EXPECT_EQ(s, org_colSum[i]);
  }
}

TEST(kk, t5) {
  Solution sol;
  vector<int> rowSum = {0}, colSum = {0};
  auto org_rowSum = rowSum;
  auto org_colSum = colSum;
  int r = rowSum.size();
  int c = colSum.size();
  auto ans = sol.restoreMatrix(rowSum, colSum);
  for (int i = 0; i < r; i++) {
    int s = accumulate(ans[i].begin(), ans[i].end(), 0);
    EXPECT_EQ(s, org_rowSum[i]);
  }
  for (int i = 0; i < c; i++) {
    int s = 0;
    for (int j = 0; j < r; j++) {
      s += ans[j][i];
    }
    EXPECT_EQ(s, org_colSum[i]);
  }
}

TEST(kk, t6) {
  Solution sol;
  vector<int> rowSum = {22, 23, 45, 35, 38, 23, 16, 28, 30},
              colSum = {3, 21, 184, 26, 13, 12, 1};

  auto org_rowSum = rowSum;
  auto org_colSum = colSum;
  int r = rowSum.size();
  int c = colSum.size();
  auto ans = sol.restoreMatrix(rowSum, colSum);
  for (int i = 0; i < r; i++) {
    int s = accumulate(ans[i].begin(), ans[i].end(), 0);
    EXPECT_EQ(s, org_rowSum[i]);
  }
  for (int i = 0; i < c; i++) {
    int s = 0;
    for (int j = 0; j < r; j++) {
      s += ans[j][i];
    }
    EXPECT_EQ(s, org_colSum[i]);
  }
}

