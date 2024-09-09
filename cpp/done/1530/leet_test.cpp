#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;

  EXPECT_EQ(sol.countPairs(nullptr, 3), 0);
}

TEST(kk, t2) {
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(4);

  EXPECT_EQ(sol.countPairs(root, 3), 3);
  EXPECT_EQ(sol.countPairs(root, 2), 1);
  delete root;
}

