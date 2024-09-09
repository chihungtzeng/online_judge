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
  int countPairs(TreeNode *root, int distance) {
    auto ret = helper(root, distance);
    return ret.second;
  }
  pair<vector<int>, int> helper(TreeNode *root, const int distance) {
    vector<int> dist_cnt(11);
    int ans = 0;
    if (!root) return {dist_cnt, ans};
    auto rret = helper(root->right, distance);
    auto lret = helper(root->left, distance);
    if (root->left || root->right) {
      ans = lret.second + rret.second;
      for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
          if (i + j + 2 <= distance) {
            ans += lret.first[i] * rret.first[j];
          }
        }
      }
    } else {
      dist_cnt[0] = 1;
    }
    for (int i = 0; i < 10; i++) {
      dist_cnt[i + 1] = lret.first[i] + rret.first[i];
    }
    // LOG(INFO) << "Node " << root->val << " ans: " << ans << " dist_cnt size:
    // " << dist_cnt.size();
    return {dist_cnt, ans};
  }
};
