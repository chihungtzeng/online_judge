#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (!root->left) {
        TreeNode* temp = root->right;
        root->right = nullptr;
        delete root;
        return temp;
      } else if (!root->right) {
        TreeNode* temp = root->left;
        root->left = nullptr;
        delete root;
        return temp;
      } else {
        TreeNode* cur = root->left;
        while (cur && cur->right) {
          cur = cur->right;
        }
        root->val = cur->val;
        root->left = deleteNode(root->left, cur->val);
      }
    }
    return root;
  }
};
