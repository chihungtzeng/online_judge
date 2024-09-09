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

using tpair = pair<TreeNode*, TreeNode*>;
class Solution
{
public:
  int longestUnivaluePath(TreeNode* root)
  {
    if (!root)
      return 0;

    vector<TreeNode*> stack;
    stack.push_back(root);
    int ans = INT_MIN;

    while (!stack.empty())
    {
      auto cur = stack.back();
      stack.pop_back();
      vector<tpair> edges;
      deque<TreeNode*> q;
      q.push_back(cur);

      while (!q.empty())
      {
        auto cur = q.front();
        q.pop_front();
        if (cur->left)
        {
          if (cur->left->val == cur->val)
          {
            q.push_back(cur->left);
            edges.push_back({ cur, cur->left });
          }
          else
          {
            stack.push_back(cur->left);
          }
        }
        if (cur->right)
        {
          if (cur->right->val == cur->val)
          {
            q.push_back(cur->right);
            edges.push_back({ cur, cur->right });
          }
          else
          {
            stack.push_back(cur->right);
          }
        }
      }
      ans = max(ans, longest_path_of(edges));
    }
    return ans;
  }
  int longest_path_of(vector<tpair>& edges)
  {
    // LOG(INFO) << "# edges: " << edges.size();
    map<TreeNode*, vector<TreeNode*>> nbrs;
    map<TreeNode*, int> level;
    for (auto& [u, v] : edges)
    {
      nbrs[u].push_back(v);
      nbrs[v].push_back(u);
      level[u] = 0;
      level[v] = 0;
    }
    deque<TreeNode*> q;
    map<TreeNode*, int> degrees;
    for (auto& [key, val] : nbrs)
    {
      degrees[key] = val.size();
      if (degrees[key] == 1)
      {
        q.push_back(key);
      }
    }
    while (!q.empty())
    {
      auto cur = q.front();
      q.pop_front();
      degrees[cur]--;
      for (auto v : nbrs[cur])
      {
        degrees[v]--;
        if (degrees[v] == 1)
        {
          level[v] = max(level[v], level[cur] + 1);
          q.push_back(v);
        }
      }
    }
    int max_level = 0, nmax = 0;
    for (auto& [v, ell] : level)
    {
      if (ell > max_level)
      {
        max_level = ell;
        nmax = 1;
      }
      else if (ell == max_level)
      {
        nmax++;
      }
    }
    if (nmax > 1)
      return 2 * max_level + 1;
    else
      return 2 * max_level;
  }
};
