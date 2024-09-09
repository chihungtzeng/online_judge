#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  auto *root = new Node(1);
  root->children.push_back(new Node(3));
  root->children.push_back(new Node(2));
  root->children.push_back(new Node(4));
  root->children[0]->children.push_back(new Node(5));
  root->children[0]->children.push_back(new Node(6));

  vector<vector<int>> expect{{1},{3,2,4},{5,6}};
  EXPECT_EQ(sol.levelOrder(root), expect);
  delete root;
}

TEST(kk, t2) {
  Solution sol;
  EXPECT_EQ(sol.levelOrder(nullptr).size(), 0);
}

