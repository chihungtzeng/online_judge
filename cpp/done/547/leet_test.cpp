#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<vector<int>> M{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

  EXPECT_EQ(sol.findCircleNum(M), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<vector<int>> M{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

  EXPECT_EQ(sol.findCircleNum(M), 2);
}

TEST(kk, t2_1) {
  Solution sol;
  vector<vector<int>> M{{1}};

  EXPECT_EQ(sol.findCircleNum(M), 1);
}



TEST(kk, t3) {
  Solution sol;
  int n = 7;
  vector<vector<int>> M(n, vector<int>(n, 0));
  for(int i=0; i<n; i++) M[i][i] = 1;
  M[0][4] = 1;
  M[0][6] = 1;
  M[1][3] = 1;
  M[2][5] = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      M[i][j] = M[j][i];
    }
  }
  for(int i=0; i<n; i++){
    LOG(INFO) << M[i];
  }

  EXPECT_EQ(sol.findCircleNum(M), 3);
}

