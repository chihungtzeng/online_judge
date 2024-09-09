#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode() : val(0), left(NULL), right(NULL) {}
};
class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int height = 0;
    for (TreeNode *cur = root; cur != nullptr; cur = cur->left) {
      height++;
    }
    return countNodes(root, height);
  }
  int countNodes(TreeNode *root, int height) {
    if (height == 1) {
      return 1;
    }
    int nright = 0;
    int nleft = 0;
    int full_subtree = (1 << (height - 1)) - 1;
    if (root->right != nullptr) {
      nright = countNodes(root->right, height - 1);
    }

    if (root->left != nullptr) {
      if (nright > (full_subtree >> 1)) {
        nleft = full_subtree;
      } else {
        nleft = countNodes(root->left, height - 1);
      }
    }
    return nleft + nright + 1;
  }
};
