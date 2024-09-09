#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};
class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    unordered_map<int, int> dist;
    locate_target(root, target, dist);
#if 0
    for(auto& [k, v]: dist){
      LOG(INFO) << k << " : " << v;
    }
#endif
    vector<int> ans;
    helper(root, 0, dist, ans, K);
    return ans;
  }
  void helper(TreeNode* root, int how_far, unordered_map<int, int>& dist,
              vector<int>& ans, int K) {
    if (!root) return;
    if (dist.find(root->val) != dist.end()) {
      how_far = dist[root->val];
    }
    if (how_far == K) ans.push_back(root->val);
    helper(root->left, how_far + 1, dist, ans, K);
    helper(root->right, how_far + 1, dist, ans, K);
  }
  int locate_target(TreeNode* root, TreeNode* target,
                    unordered_map<int, int>& dist) {
    if (!root) return -1;
    if (root == target) {
      dist[root->val] = 0;
      return 0;
    }
    int lret = locate_target(root->left, target, dist);
    if (lret >= 0) {
      dist[root->val] = lret + 1;
      return lret + 1;
    }
    int rret = locate_target(root->right, target, dist);
    if (rret >= 0) {
      dist[root->val] = rret + 1;
      return rret + 1;
    }
    return -1;
  }
};
