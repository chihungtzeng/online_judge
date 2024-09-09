#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  const int n = 3;
  vector<ListNode *> ell(n);
  for(int i=0; i<n; i++){
    ell[i] = new ListNode(i+1);
  }
  for(int i=0; i<n-1; i++){
    ell[i]->next = ell[i+1];
  }

  auto actual = sol.splitListToParts(ell[0], 5);
  EXPECT_EQ(actual.size(), 5);
  EXPECT_EQ(actual[0], ell[0]);
  EXPECT_EQ(actual[1], ell[1]);
  EXPECT_EQ(actual[2], ell[2]);
  EXPECT_EQ(actual[3], nullptr);
  EXPECT_EQ(actual[4], nullptr);
  for(int i=0; i<n; i++) delete ell[i];
}

TEST(kk, t2) {
  Solution sol;
  const int n = 10;
  vector<ListNode *> ell(n);
  for(int i=0; i<n; i++){
    ell[i] = new ListNode(i+1);
  }
  for(int i=0; i<n-1; i++){
    ell[i]->next = ell[i+1];
  }

  auto actual = sol.splitListToParts(ell[0], 3);
  EXPECT_EQ(actual.size(), 3);
  EXPECT_EQ(actual[0], ell[0]);
  EXPECT_EQ(actual[1], ell[4]);
  EXPECT_EQ(actual[2], ell[7]);
  for(int i=0; i<n; i++) delete ell[i];
}

