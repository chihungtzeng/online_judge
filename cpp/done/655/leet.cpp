#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
  {
  }
  ~TreeNode()
  {
    if (left)
      delete left;
    if (right)
      delete right;
  }
};
class Solution
{
public:
  vector<vector<string>> printTree(TreeNode* root)
  {
    int height = height_of(root);
    // LOG(INFO) << "height: " << height;
    int n = (1 << (height + 1)) - 1;
    vector<vector<string>> ans(height + 1, vector<string>(n, ""));
    label(root, 0, (n - 1) >> 1, ans, height);
    return ans;
  }

  void label(const TreeNode* root, const int r, const int c, vector<vector<string>>& ans, const int height)
  {
    if (!root)
      return;
    ans[r][c] = to_string(root->val);
    int exp_shift = height - r - 1;
    if (exp_shift >= 0)
    {
      int offset = (1 << exp_shift);
      label(root->left, r + 1, c - offset, ans, height);
      label(root->right, r + 1, c + offset, ans, height);
    }
  }

  int height_of(TreeNode* root)
  {
    if (!root)
      return -1;
    return max(height_of(root->left), height_of(root->right)) + 1;
  }
};
