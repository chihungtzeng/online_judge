#include "leet.cpp"

#include <gtest/gtest.h>

#include <cassert>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  Solution sol;
  int n = 4;
  vector<int> leftChild = {1, -1, 3, -1}, rightChild = {2, -1, -1, -1};
  EXPECT_EQ(sol.validateBinaryTreeNodes(n, leftChild, rightChild), true);
}

TEST(kk, t2) {
  Solution sol;
  int n = 4;
  vector<int> leftChild = {1, -1, 3, -1}, rightChild = {2, 3, -1, -1};
  EXPECT_EQ(sol.validateBinaryTreeNodes(n, leftChild, rightChild), false);
}

TEST(kk, t3) {
  Solution sol;
  int n = 2;
  vector<int> leftChild = {1, 0}, rightChild = {-1, -1};
  EXPECT_EQ(sol.validateBinaryTreeNodes(n, leftChild, rightChild), false);
}

TEST(kk, t4) {
  Solution sol;
  int n = 6;
  vector<int> leftChild = {1, -1, -1, 4, -1, -1},
              rightChild = {2, -1, -1, 5, -1, -1};
  EXPECT_EQ(sol.validateBinaryTreeNodes(n, leftChild, rightChild), false);
}

TEST(kk, t5) {
  Solution sol;
  int n = 4;
  vector<int> leftChild = {1, 2, 0, -1}, rightChild = {-1, -1, -1, -1};
  EXPECT_EQ(sol.validateBinaryTreeNodes(n, leftChild, rightChild), false);
}

