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
  int64_t total;
  unordered_set<int64_t> weights;
  const int base = 1e9 + 7;
  int maxProduct(TreeNode *root) {
    total = calc_weight(root);
    int64_t ans = 0;
    for (auto &v : weights) {
      ans = max(ans, v * (total - v));
    }
    return ans % base;
  }
  int64_t calc_weight(TreeNode *root) {
    if (!root) return 0;
    int64_t lw = calc_weight(root->left);
    int64_t rw = calc_weight(root->right);
    if (lw > 0) weights.insert(lw);
    if (rw > 0) weights.insert(rw);
    return lw + rw + root->val;
  }
};
