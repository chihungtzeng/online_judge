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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
      return new TreeNode(val);
    }
    TreeNode *cur = root, *prev = nullptr;
    while (cur) {
      prev = cur;
      if (val > cur->val) {
        cur = cur->right;
      } else {
        cur = cur->left;
      }
    }
    if (val > prev->val) {
      prev->right = new TreeNode(val);
    } else {
      prev->left = new TreeNode(val);
    }
    return root;
  }
};
