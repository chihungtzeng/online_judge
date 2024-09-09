#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);
  root = sol.addOneRow(root, 1, 3);
  delete root;
}

TEST(kk, t2) {
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root = sol.addOneRow(root, 5, 4);
  EXPECT_EQ(root->left->left->left->val, 5);
  EXPECT_EQ(root->left->left->right->val, 5);
  delete root;
}

TEST(kk, t3) {
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root = sol.addOneRow(root, 4, 1);
  EXPECT_EQ(root->val, 4);
  EXPECT_EQ(root->left->val, 1);
  delete root;
}

