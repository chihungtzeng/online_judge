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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  TreeNode *addOneRow(TreeNode *root, int v, int d) {
    if (d == 1) {
      TreeNode *new_root = new TreeNode(v);
      new_root->left = root;
      return new_root;
    }

    vector<TreeNode *> res;
    find_nodes_by_depth(root, d - 1, 1, res);
    for (auto node_ptr : res) {
      if (node_ptr->left) {
        TreeNode *l = new TreeNode(v);
        l->left = node_ptr->left;
        node_ptr->left = l;
      } else {
        node_ptr->left = new TreeNode(v);
      }

      if (node_ptr->right) {
        TreeNode *l = new TreeNode(v);
        l->right = node_ptr->right;
        node_ptr->right = l;
      } else {
        node_ptr->right = new TreeNode(v);
      }
    }
    return root;
  }
  void find_nodes_by_depth(TreeNode *root, int d, int cur_depth,
                           vector<TreeNode *> &res) {
    if (!root) return;
    if (cur_depth == d) {
      res.push_back(root);
      return;
    } else if (cur_depth < d) {
      find_nodes_by_depth(root->left, d, cur_depth + 1, res);
      find_nodes_by_depth(root->right, d, cur_depth + 1, res);
    }
  }
};
