/**
 * Definition for a binary tree node.
 */
#include <cstddef>
#include <cmath>
#include<algorithm>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Porder {
  int height;
  bool isBalanced;
};

class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (!root) {
      return true;
    }

    auto lporder = postorder(root->left);
    if (!lporder.isBalanced) {
      return false;
    }
    auto rporder = postorder(root->right);

    if (!rporder.isBalanced) {
      return false;
    }

    return bool(std::abs(lporder.height - rporder.height) <= 1);
  }

  struct Porder postorder(TreeNode *root) {
    struct Porder porder;
    porder.height = 1;
    porder.isBalanced = true;
    if (!root) {
      return porder;
    }
    auto lporder = postorder(root->left);
    if (!lporder.isBalanced) {
      porder.isBalanced = false;
      return porder;
    }

    auto rporder = postorder(root->right);
    if (!rporder.isBalanced) {
      porder.isBalanced = false;
      return porder;
    }
    porder.height = std::max(lporder.height, rporder.height) + 1;
    porder.isBalanced =
        bool(std::abs(lporder.height - rporder.height) <= 1) && lporder.isBalanced && rporder.isBalanced;
    return porder;
  }
};
