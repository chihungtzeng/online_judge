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
  map<int, int> lvs_;
  vector<int> largestValues(TreeNode *root) {
    lvs_.clear();
    helper(root, 0);
    vector<int> ret(lvs_.size());
    for (auto &[key, val] : lvs_) {
      ret[key] = val;
    }
    return ret;
  }

  void helper(TreeNode *root, const int depth) {
    if (!root) return;
    auto it = lvs_.find(depth);
    if (it == lvs_.end()) {
      lvs_[depth] = root->val;
    } else {
      it->second = max(it->second, root->val);
    }

    helper(root->left, depth + 1);
    helper(root->right, depth + 1);
  }
};
