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
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  int best_;
  int maxSumBST(TreeNode *root) {
    best_ = 0;
    vector<int> res(4);
    helper(root);
    return best_;
  }
  vector<int> helper(TreeNode *root) {
    // is_bst, sum, max, min
    vector<int> ret(4);
    if (!root->left && !root->right) {
      ret[0] = 1;
      ret[1] = root->val;
      ret[2] = root->val;
      ret[3] = root->val;
      best_ = max(best_, ret[1]);
      return ret;
    } else if (root->left && !root->right) {
      auto ret_left = helper(root->left);
      if (ret_left[0] && root->val > ret_left[2]) {
        ret[0] = 1;
        ret[1] = root->val + ret_left[1];
        ret[2] = root->val;
        ret[3] = ret_left[3];
      }
    } else if (!root->left && root->right) {
      auto ret_right = helper(root->right);
      if (ret_right[0] && root->val < ret_right[3]) {
        ret[0] = 1;
        ret[1] = root->val + ret_right[1];
        ret[2] = ret_right[2];
        ret[3] = root->val;
      }
    } else {
      auto ret_left = helper(root->left);
      auto ret_right = helper(root->right);
      if (ret_left[0] && ret_right[1]) {
        ret[0] = (root->val > ret_left[2] && root->val < ret_right[3]);
      }

      if (ret[0]) {
        ret[1] = ret_left[1] + ret_right[1] + root->val;
        ret[2] = ret_right[2];
        ret[3] = ret_left[3];
      }
    }

    if (ret[1] > best_) best_ = ret[1];
    return ret;
  }
};
