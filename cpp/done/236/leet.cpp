#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct LCA {
  TreeNode *lca;
  int nhit;
  LCA(): lca(nullptr), nhit(0) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto ret = hitpq(root, p, q);
    if (ret.lca) {
      return ret.lca;
    } else {
      return root;
    }
  }
  struct LCA hitpq(TreeNode* root, TreeNode* p, TreeNode* q) {
    struct LCA ret;
    if (!root) {
      return ret;
    }
    auto lret = hitpq(root->left, p, q);
    if (lret.lca) {
      return lret;
    }
    auto rret = hitpq(root->right, p, q);
    if (rret.lca) {
      return rret;
    }
    ret.nhit = lret.nhit + rret.nhit;
    if ((root == p) || (root == q))
    {
      ret.nhit += 1;
    }
    if (ret.nhit == 2){
      ret.lca = root;
    }
    return ret;
  }
};
