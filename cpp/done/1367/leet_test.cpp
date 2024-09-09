#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  ListNode *head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(8);
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(4);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(6);
  root->right->left->right = new TreeNode(8);
  root->right->left->right->left = new TreeNode(1);
  root->right->left->right->right = new TreeNode(3);


  EXPECT_EQ(sol.isSubPath(head, root), true);
  delete head;
  delete root;
}

