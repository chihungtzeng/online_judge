#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  auto root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(1);
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(5);

  EXPECT_EQ(sol.longestUnivaluePath(root), 2);
  delete root;
}

TEST(kk, t2) {
  Solution sol;
  auto root = new TreeNode(1);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(5);

  EXPECT_EQ(sol.longestUnivaluePath(root), 2);
  delete root;
}

TEST(kk, t3) {
  Solution sol;
  auto root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(1);
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(5);
  root->right->right->left = new TreeNode(5);
  root->right->right->right = new TreeNode(5);

  EXPECT_EQ(sol.longestUnivaluePath(root), 3);
  delete root;
}

TEST(kk, t4) {
  Solution sol;
  auto root = new TreeNode(5);
  root->left = new TreeNode(5);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(5);
  root->right->right->right = new TreeNode(5);
  root->right->left = new TreeNode(5);
  root->right->left->left = new TreeNode(5);
  root->right->left->right = new TreeNode(5);
  root->right->left->right->right = new TreeNode(5);
  root->right->left->right->right->right = new TreeNode(5);

  EXPECT_EQ(sol.longestUnivaluePath(root), 6);
  delete root;
}

TEST(kk, t5) {
  Solution sol;
  auto root = new TreeNode(5);
  deque<TreeNode*> q;
  q.push_back(root);
  int nbranch = 10000;

  while(!q.empty() && nbranch--)
  {
    auto cur = q.front();
    q.pop_front();
    cur->left = new TreeNode(5);
    cur->right = new TreeNode(5);
    q.push_back(cur->left);
    q.push_back(cur->right);
  }


  EXPECT_EQ(sol.longestUnivaluePath(root), 27);
  delete root;
}





