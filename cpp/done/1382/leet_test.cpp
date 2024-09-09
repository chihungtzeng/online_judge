#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->right = new TreeNode(3);
  root->right->right->right = new TreeNode(4);

  TreeNode* nroot = sol.balanceBST(root);
  vector<int> vals;
  sol.vals_of(nroot, vals);
  LOG(INFO) << vals;
  delete root;
  delete nroot;
}

