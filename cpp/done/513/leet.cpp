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

using node_pair = std::pair<TreeNode *, int>;
class Solution {
 public:
  int findBottomLeftValue(TreeNode *root) {
    int max_depth = -1;
    int ret = -1;
    std::deque<node_pair> dq;
    dq.push_back({root, 0});
    while (!dq.empty()) {
      auto cur = dq.front();
      dq.pop_front();
      if (cur.second > max_depth) {
        max_depth = cur.second;
        ret = cur.first->val;
      }
      if (cur.first->left) {
        dq.push_back({cur.first->left, cur.second + 1});
      }
      if (cur.first->right) {
        dq.push_back({cur.first->right, cur.second + 1});
      }
    }
    return ret;
  }
};
