#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode nodes[6];
  for(auto i=0; i<6; i++)
  {
    nodes[i].val = i;
  }
  nodes[1].left = &nodes[2];
  nodes[1].right = &nodes[3];
  nodes[2].right = &nodes[5];

  vector<string> expect{"1->2->5", "1->3"};

  EXPECT_EQ(sol.binaryTreePaths(&nodes[1]), expect);
}

TEST(kk, t2) {
  Solution sol;
  vector<string> expect;

  EXPECT_EQ(sol.binaryTreePaths(nullptr), expect);
}

