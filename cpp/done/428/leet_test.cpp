#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t0) {
  Codec codec;
  auto s =  codec.serialize(nullptr);
  EXPECT_EQ(s, "{}");
}

TEST(kk, t1) {
  Codec codec;
  Node* root = new Node(1);
  root->children.push_back(new Node(3));
  root->children.push_back(new Node(2));
  root->children.push_back(new Node(4));
  root->children[0]->children.push_back(new Node(5));
  root->children[0]->children.push_back(new Node(6));
  root->children[0]->children.push_back(new Node(7));
  for(int i=10; i<100;i++){
  root->children[0]->children.push_back(new Node(i));
  }

  auto s =  codec.serialize(root);
  LOG(INFO) << s;
  string_view sv(s);
  LOG(INFO) << "sizeof(sv):" << sizeof(sv) << " : " << sv;
  auto new_root = codec.deserialize(s);
  auto new_s = codec.serialize(new_root);
  EXPECT_EQ(s, new_s);
  delete root;
  delete new_root;
}

