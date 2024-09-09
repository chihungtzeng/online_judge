#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Codec codec;
  TreeNode *root = nullptr;
  string s = codec.serialize(root);
  EXPECT_EQ(s, "");
  TreeNode *ret = codec.deserialize(s);
  EXPECT_EQ(ret, nullptr);
}

TEST(kk, t2) {
  Codec codec;
  TreeNode *root = new TreeNode(10);
  string s = codec.serialize(root);
  EXPECT_EQ(s, "10");
  TreeNode *ret = codec.deserialize(s);
  EXPECT_EQ(ret->val, root->val);
  delete root;
  delete ret;
}

