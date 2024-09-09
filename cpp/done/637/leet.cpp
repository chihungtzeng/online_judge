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
};
using ipair = pair<int64_t, int>;
class Solution
{
public:
  vector<double> averageOfLevels(TreeNode* root)
  {
    vector<ipair> sum_at_depth;
    helper(root, 0, sum_at_depth);
    vector<double> ans;
    for (auto& [sum, num] : sum_at_depth)
    {
      ans.push_back(double(sum) / num);
    }
    return ans;
  }
  void helper(TreeNode* root, const int depth, vector<ipair>& sum_at_depth)
  {
    if (!root)
      return;
    if (sum_at_depth.size() <= depth)
    {
      sum_at_depth.push_back({ root->val, 1 });
    }
    else
    {
      sum_at_depth[depth].first += root->val;
      sum_at_depth[depth].second += 1;
    }
    helper(root->left, depth + 1, sum_at_depth);
    helper(root->right, depth + 1, sum_at_depth);
  }
};
