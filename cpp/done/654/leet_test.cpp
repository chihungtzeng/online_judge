#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  vector<int> nums;

  EXPECT_EQ(sol.constructMaximumBinaryTree(nums), nullptr);
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{5};
  auto* root = sol.constructMaximumBinaryTree(nums);

  EXPECT_EQ(root->val, 5);
  EXPECT_EQ(root->left, nullptr);
  EXPECT_EQ(root->right, nullptr);
  delete root;
}

