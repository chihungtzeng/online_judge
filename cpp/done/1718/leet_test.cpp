#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t0) {
  Solution sol;
  vector<int> expect{1};
  EXPECT_EQ(sol.constructDistancedSequence(1), expect);
}

TEST(kk, t0_2) {
  Solution sol;
  vector<int> expect{2,1,2};
  EXPECT_EQ(sol.constructDistancedSequence(2), expect);
}

TEST(kk, t1) {
  Solution sol;
  vector<int> expect{3,1,2,3,2};
  EXPECT_EQ(sol.constructDistancedSequence(3), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> expect{5,3,1,4,3,5,2,4,2};
  EXPECT_EQ(sol.constructDistancedSequence(5), expect);
}

TEST(kk, t3) {
  Solution sol;
  for(int n=5; n<=20; n++){
    auto actual = sol.constructDistancedSequence(n);
    vector<int> idxes(n+1, -1);
    for(int i=0; i<actual.size(); i++){
      auto val = actual[i];
      if (idxes[val] == -1){
        idxes[val] = i;
      } else {
        EXPECT_EQ(i - idxes[val], val);
      }
    }
  }
}

