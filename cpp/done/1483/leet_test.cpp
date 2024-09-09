#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  vector<int> parent{-1,0,0,1,1,2,2};
  int n = 7;
  TreeAncestor* obj = new TreeAncestor(n, parent);
  EXPECT_EQ(obj->getKthAncestor(3, 1), 1);
  EXPECT_EQ(obj->getKthAncestor(5, 2), 0);
  EXPECT_EQ(obj->getKthAncestor(6,3), -1);
  EXPECT_EQ(obj->getKthAncestor(6,2), 0);
  EXPECT_EQ(obj->getKthAncestor(6,50000), -1);
  delete obj;
}

TEST(kk, t2) {
  int n=50000;
  vector<int> parent(n);
  parent[0] = -1;
  for(int i=1; i<n;i++){
    parent[i] = i-1;
  }
  TreeAncestor* obj = new TreeAncestor(n, parent);
  EXPECT_EQ(obj->getKthAncestor(n-1, n-1-10000), 10000);
  EXPECT_EQ(obj->getKthAncestor(n-1,n), -1);
  delete obj;
}

