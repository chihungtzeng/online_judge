#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode* root = new TreeNode(0);
  root->right = new TreeNode(1);
  root->right->right = new TreeNode(2);
  root->right->right->right = new TreeNode(3);
  vector<int> expect{3};
  EXPECT_EQ(sol.distanceK(root, root->right, 2), expect);
  delete root;
}

