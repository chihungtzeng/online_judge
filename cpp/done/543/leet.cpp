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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode *root) {
    map<TreeNode *, int> height_cache;
    if (!root) return 0;
    int ret =
        height(root->left, height_cache) + height(root->right, height_cache);
    if (root->left) {
      ret = max(ret, diameterOfBinaryTree(root->left));
    }
    if (root->right) {
      ret = max(ret, diameterOfBinaryTree(root->right));
    }
    return ret;
  }
  int height(TreeNode *root, map<TreeNode *, int> &height_cache) {
    if (!root) return 0;
    auto it = height_cache.find(root);
    if (it != height_cache.end()) return it->second;
    int ret = 1 + max(height(root->left, height_cache),
                      height(root->right, height_cache));
    height_cache[root] = ret;
    return ret;
  }
};
