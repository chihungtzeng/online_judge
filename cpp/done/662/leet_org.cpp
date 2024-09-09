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
    vector<int64_t> left, right;
    visit(root, 0, 0, left, right);
    int64_t ans = 0;
    for (int i = 0; i < left.size(); i++) {
      ans = max(ans, right[i] - left[i] + 1);
    }
    return ans;
  }
  void visit(TreeNode *root, int64_t index, int level, vector<int64_t> &left,
             vector<int64_t> &right) {
    if (!root) return;
    if (left.size() <= level) {
      left.resize(level + 1);
      right.resize(level + 1);
      left[level] = LLONG_MAX;
      right[level] = 0;
    }
    left[level] = min(left[level], index);
    right[level] = max(right[level], index);
    visit(root->left, 2 * index + 1, level + 1, left, right);
    visit(root->right, 2 * index + 2, level + 1, left, right);
  }
};
