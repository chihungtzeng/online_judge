#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->left->right = new TreeNode(3);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(1);

  EXPECT_EQ(sol.rob(root), 7);

  delete root->left->right;
  delete root->left;
  delete root->right->right;
  delete root->right;
  delete root;
}

