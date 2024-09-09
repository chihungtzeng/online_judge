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
  ~TreeNode() {if (left) delete left; if (right) delete right;}
};
class Solution {
 public:
  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> cache;
    helper(root, cache);
    int max_cnt = 0;
    for (auto &[key, val] : cache) {
      max_cnt = max(max_cnt, val);
    }
    vector<int> ret;
    for (auto &[key, val] : cache) {
      if (val == max_cnt) {
        ret.push_back(key);
      }
    }
    return ret;
  }
  int helper(TreeNode *root, unordered_map<int, int> &cache) {
    if (!root) return 0;
    int sum =
        helper(root->left, cache) + helper(root->right, cache) + root->val;
    auto it = cache.find(sum);
    if (it == cache.end()) {
      cache[sum] = 1;
    } else {
      it->second += 1;
    }
    return sum;
  }
};
