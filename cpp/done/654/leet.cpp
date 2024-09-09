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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.empty()) return nullptr;
    auto it = max_element(nums.begin(), nums.end());
    vector<int> lvals(nums.begin(), it), rvals(it + 1, nums.end());
    return new TreeNode(*it, constructMaximumBinaryTree(lvals),
                        constructMaximumBinaryTree(rvals));
  }
};
