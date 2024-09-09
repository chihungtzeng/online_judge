#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode *root = new TreeNode(5);

  EXPECT_EQ(sol.widthOfBinaryTree(nullptr), 0);
  EXPECT_EQ(sol.widthOfBinaryTree(root), 1);
  delete root;
}

TEST(kk, t2) {
  Solution sol;
  TreeNode *root = new TreeNode(1, new TreeNode(3), new TreeNode(2));
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(9);

  EXPECT_EQ(sol.widthOfBinaryTree(root), 4);
  delete root;
}

