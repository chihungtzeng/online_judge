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
  TreeNode *trimBST(TreeNode *root, int L, int R) {
    if (!root) return root;
    if (root->val >= L && root->val <= R) {
      root->left = trimBST(root->left, L, R);
      root->right = trimBST(root->right, L, R);
    } else if (root->val < L) {
      return trimBST(root->right, L, R);
    } else if (root->val > R) {
      return trimBST(root->left, L, R);
    }
    return root;
  }
};
