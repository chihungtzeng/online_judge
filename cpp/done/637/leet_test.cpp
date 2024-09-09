#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  TreeNode* root = new TreeNode(3);
  TreeNode* l1 = new TreeNode(9);
  TreeNode* r1 = new TreeNode(20);
  TreeNode* rl1 = new TreeNode(15);

  root->left = l1;
  root->right = r1;
  r1->left = rl1;

  vector<double> expect{ 3.0, 14.5, 15.0 };
  EXPECT_EQ(sol.averageOfLevels(root), expect);
  delete rl1;
  delete r1;
  delete l1;
  delete root;
}

TEST(kk, t2)
{
  Solution sol;
  TreeNode* l1 = new TreeNode(2147483647);
  TreeNode* r1 = new TreeNode(2147483647);
  TreeNode* root = new TreeNode(2147483647, l1, r1);


  vector<double> expect{ 2147483647,2147483647 };
  EXPECT_EQ(sol.averageOfLevels(root), expect);
  delete r1;
  delete l1;
  delete root;
}

