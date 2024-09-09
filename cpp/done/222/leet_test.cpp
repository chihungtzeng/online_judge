#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1) {
  Solution sol;
  std::vector<TreeNode> nodes(8);
  for(int i=1; i<4; i++)
  {
    nodes[i].left = &nodes[i*2];
    nodes[i].right = &nodes[i*2 + 1];
  }
  nodes[3].right = nullptr;

  EXPECT_EQ(sol.countNodes(&nodes[1]), 6);
}

TEST(kk, t2) {
  Solution sol;
  TreeNode node;

  EXPECT_EQ(sol.countNodes(&node), 1);
}

TEST(kk, t3) {
  Solution sol;

  EXPECT_EQ(sol.countNodes(nullptr), 0);
}

TEST(kk, t4) {
  Solution sol;
  std::vector<TreeNode> nodes(2);
  nodes[0].left = &nodes[1];

  EXPECT_EQ(sol.countNodes(&nodes[0]), 2);
}


TEST(kk, t5) {
  Solution sol;
  for (int nnodes = 0; nnodes < 100; nnodes++) {
    std::vector<TreeNode> nodes;
    for (int i = 0; i < nnodes; i++) {
      nodes.emplace_back(TreeNode(i));
    }
    for (int i = 0; i < nnodes / 2; i++) {
      int lidx = i * 2 + 1;
      int ridx = lidx + 1;
      if (lidx < nodes.size()) {
        nodes[i].left = &nodes[i * 2 + 1];
      }
      if (ridx < nodes.size()) {
        nodes[i].right = &nodes[i * 2 + 2];
      }
    }

    EXPECT_EQ(sol.countNodes(&nodes[0]), nnodes);
  }
}


