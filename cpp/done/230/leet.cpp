#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    vector<int> vals;
    vals.reserve(k);
    inorder(root->left, vals);
    vals.push_back(root->val);
    if (vals.size() >= k) {
      return vals[k - 1];
    } else {
      inorder(root->right, vals);
      return vals[k - 1];
    }
  }
  void inorder(TreeNode *root, vector<int> &vals) {
    if (!root) return;
    inorder(root->left, vals);
    vals.push_back(root->val);
    inorder(root->right, vals);
  }
};
