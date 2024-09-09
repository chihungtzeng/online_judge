#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode *root= new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(4);
  root->right->left->left = new TreeNode(4);

  EXPECT_EQ(sol.findDuplicateSubtrees(root).size(), 2);
  delete root;
}

