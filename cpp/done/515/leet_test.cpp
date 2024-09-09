#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(14);
  root->left->left = new TreeNode(1);
  vector<int> expect{5,14,1};
  EXPECT_EQ(sol.largestValues(root), expect);
  delete root;
}

