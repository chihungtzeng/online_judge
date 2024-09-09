#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);

  vector<vector<string>> expect{ { "", "1", "" }, { "2", "", "" } };

  EXPECT_EQ(sol.printTree(root), expect);
  delete root;
}

TEST(kk, t2)
{
  Solution sol;

  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);

  vector<vector<string>> expect{ { "", "", "", "1", "", "", "" },
                                 { "", "2", "", "", "", "3", "" },
                                 { "", "", "4", "", "", "", "" } };

  EXPECT_EQ(sol.printTree(root), expect);
  delete root;
}

