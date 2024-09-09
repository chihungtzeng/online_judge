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
 private:
  std::vector<string> paths;

 public:
  vector<string> binaryTreePaths(TreeNode *root) {
    paths.clear();
    paths.reserve(128);
    vector<int> vals;
    if (root) {
      helper(root, vals);
    }
    return paths;
  }
  void helper(TreeNode *root, vector<int> &vals) {
    if (!root->left && !root->right) {
      string s;
      for (auto v : vals) {
        s += std::to_string(v) + "->";
      }
      s += std::to_string(root->val);
      paths.emplace_back(s);
    }
    vals.push_back(root->val);

    if (root->left) {
      helper(root->left, vals);
    }

    if (root->right) {
      helper(root->right, vals);
    }

    vals.pop_back();
  }
};
