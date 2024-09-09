#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
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
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  TreeNode* balanceBST(TreeNode* root) {
    if (!root) return root;
    vector<int> vals;
    vals_of(root, vals);
    return build_bst(vals, 0, vals.size() - 1);
  }
  void vals_of(TreeNode* root, vector<int>& vals) {
    if (!root) return;
    vals_of(root->left, vals);
    vals.push_back(root->val);
    vals_of(root->right, vals);
  }
  TreeNode* build_bst(vector<int>& vals, int left, int right) {
    if (left > right) return nullptr;
    if (left == right) {
      return new TreeNode(vals[left]);
    }

    int mid = (left + right) / 2;
    TreeNode* root = new TreeNode(vals[mid]);
    root->left = build_bst(vals, left, mid - 1);
    root->right = build_bst(vals, mid + 1, right);
    return root;
  }
};
