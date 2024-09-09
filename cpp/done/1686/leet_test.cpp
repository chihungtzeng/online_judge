#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> aliceValues = {1,3}, bobValues = {2,1};
  EXPECT_EQ(sol.stoneGameVI(aliceValues, bobValues), 1);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> aliceValues = {1,2}, bobValues = {3,1};
  EXPECT_EQ(sol.stoneGameVI(aliceValues, bobValues), 0);
}

TEST(kk, t3) {
  Solution sol;
  vector<int> aliceValues = {2,4,3}, bobValues = {1,6,7};
  EXPECT_EQ(sol.stoneGameVI(aliceValues, bobValues), -1);
}

TEST(kk, t4) {
  Solution sol;
  vector<int> aliceValues{46, 80, 60, 46, 42, 77, 83, 87, 41, 15, 74, 11, 76, 28, 46, 33, 69, 24, 80, 45};
  vector<int> bobValues{61, 82, 16, 14, 62, 83, 41, 14, 77, 14, 74, 20, 54, 21, 56, 91, 12, 80, 69, 21};
  /*
  srand(time(NULL));
  for(int i=0; i<20; i++){
    aliceValues.push_back(1 + rand() % 100);
    bobValues.push_back(1 + rand() % 100);
  }
  LOG(INFO) << aliceValues;
  LOG(INFO) << bobValues;
  */
  EXPECT_EQ(sol.stoneGameVI(aliceValues, bobValues), 1);
}

