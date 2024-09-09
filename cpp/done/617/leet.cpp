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
  TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 && t2) {
      TreeNode *root = new TreeNode(t1->val + t2->val);
      root->left = mergeTrees(t1->left, t2->left);
      root->right = mergeTrees(t1->right, t2->right);
      return root;
    } else if (t1 && !t2) {
      return t1;
    } else if (!t1 && t2) {
      return t2;
    } else {
      return nullptr;
    }
  }
};
