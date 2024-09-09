#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(2);

  EXPECT_EQ(sol.maxSumBST(root), 2);
  delete root;
}

TEST(kk, t2) {
  Solution sol;
  TreeNode* root = new TreeNode(-4);
  root->left = new TreeNode(-2);
  root->right = new TreeNode(-5);

  EXPECT_EQ(sol.maxSumBST(root), 0);
  delete root;
}

TEST(kk, t3) {
  Solution sol;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(4);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(2);
  root->right->right = new TreeNode(5);
  root->right->right->left = new TreeNode(4);
  root->right->right->right = new TreeNode(6);

  EXPECT_EQ(sol.maxSumBST(root), 20);
  delete root;
}

TEST(kk, t4) {
  Solution sol;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);

  root->left->left = new TreeNode(3);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(3);

  EXPECT_EQ(sol.maxSumBST(root), 7);
  delete root;
}


