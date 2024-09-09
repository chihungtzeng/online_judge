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
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};
class Solution {
 public:
  int widthOfBinaryTree(TreeNode *root) {
    vector<uint64_t> left, right;
    if (!root) return 0;
    visit(root, 0, 0, left, right);
    uint64_t ans = 0;
    for (int i = 0; i < left.size(); i++) {
      ans = max(ans, right[i] - left[i] + 1);
    }
    return ans;
  }
  void visit(TreeNode *root, uint64_t index, int level, vector<uint64_t> &left,
             vector<uint64_t> &right) {
    if (!root) return;
    if (left.size() <= level) {
      left.resize(level + 1);
      right.resize(level + 1);
      left[level] = ~0;
      right[level] = 0;
    }
    left[level] = min(left[level], index);
    right[level] = max(right[level], index);
    if (root->left) {
      visit(root->left, 2 * index + 1, level + 1, left, right);
    }
    if (root->right) {
      visit(root->right, 2 * index + 2, level + 1, left, right);
    }
  }
};
