#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
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
  std::pair<int, int> helper(TreeNode *root) {
    if (!root) {
      return {0, 0};
    }
    auto lprofit = helper(root->left);
    auto rprofit = helper(root->right);
    std::pair<int, int> profit;
    profit.first =
        max(lprofit.first, lprofit.second) + max(rprofit.first, rprofit.second);
    profit.second = lprofit.first + rprofit.first + root->val;
    return profit;
  }
  int rob(TreeNode *root) {
    auto profit = helper(root);
    return max(profit.first, profit.second);
  }
};
