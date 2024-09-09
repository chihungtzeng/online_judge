#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
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
  int pathSum(TreeNode *root, int sum) {
    vector<int> psum{0};
    return helper(root, sum, psum);
  }
  int helper(TreeNode *root, const int target, vector<int> &psum) {
    if (!root) return 0;
    int cnt = 0;
    auto back = psum.back() + root->val;
    psum.push_back(back);
    for (int i = psum.size() - 2; i >= 0; i--) {
      if (back - psum[i] == target) {
        cnt++;
      }
    }
    cnt += helper(root->left, target, psum) + helper(root->right, target, psum);
    psum.pop_back();
    return cnt;
  }
};
