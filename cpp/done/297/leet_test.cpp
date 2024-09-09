#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Codec codec;
  TreeNode *root = new TreeNode(-134);
  auto s = codec.serialize(root);
  EXPECT_EQ(s, "{-134{}{}}");
  auto *p = codec.deserialize(s);
  EXPECT_EQ(p->val, -134);
  EXPECT_EQ(p->left, nullptr);
  EXPECT_EQ(p->right, nullptr);
  delete root;
  delete p;
}

TEST(kk, t2) {
  Codec codec;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);
  auto s = codec.serialize(root);
  LOG(INFO) << s;
  auto *p = codec.deserialize(s);
  EXPECT_EQ(p->val, 1);
  EXPECT_EQ(p->left->val, 2);
  EXPECT_EQ(p->right->val, 3);
  EXPECT_EQ(p->right->left->val, 4);
  EXPECT_EQ(p->right->right->val, 5);
  delete root;
  delete p;
}
