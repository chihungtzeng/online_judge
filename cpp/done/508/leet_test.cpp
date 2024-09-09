#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(-3);

  vector<int> expect{2,-3, 4};
  sort(expect.begin(), expect.end());
  auto actual = sol.findFrequentTreeSum(root);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
  delete root;
}

TEST(kk, t2) {
  Solution sol;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(-5);

  vector<int> expect{2};
  sort(expect.begin(), expect.end());
  auto actual = sol.findFrequentTreeSum(root);
  sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expect);
  delete root;
}

