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

vector<vector<TreeNode*>> cache(21);

class Solution
{
public:
  vector<TreeNode*> allPossibleFBT(int n)
  {
    if (n == 1 && cache[1].empty())
    {
      cache[1] = { new TreeNode(0) };
    }
    if (n < 0)
      return {};
    if (n <= 2)
      return cache[n];

    if (!cache[n].empty())
      return cache[n];

    vector<vector<TreeNode*>> subtrees(n);
    for (int i = n - 1; i >= 1; i--)
    {
      subtrees[i] = allPossibleFBT(i);
      // LOG(INFO) << "subtree of size " << i << " size(): " << subtrees[i].size();
    }
    vector<TreeNode*> res;
    for (int nleft = n - 1; nleft >= 1; nleft--)
    {
      if (subtrees[nleft].empty())
        continue;
      int nright = n - 1 - nleft;
      if (subtrees[nright].empty())
        continue;

      for (int i = 0; i < subtrees[nleft].size(); i++)
      {
        for (int j = 0; j < subtrees[nright].size(); j++)
        {
          TreeNode* root = new TreeNode(0);
          root->left = subtrees[nleft][i];
          root->right = subtrees[nright][j];
          res.push_back(root);
        }
      }
    }
    if (cache[n].empty())
    {
      cache[n] = res;
    }
    // LOG(INFO) << "allPossibleFBT(" << n << "): " << res.size() << " trees";
    return res;
  }
};
