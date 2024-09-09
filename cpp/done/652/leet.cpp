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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> st;
    vector<TreeNode*> ans;
    helper(root, st, ans);
    return ans;
  }
  string helper(TreeNode* root, unordered_map<string, int>& st,
                vector<TreeNode*>& ans) {
    if (!root) return "{}";
    string s = '{' + helper(root->left, st, ans) +
               helper(root->right, st, ans) + to_string(root->val) + '}';
    // LOG(INFO) << root << ": " << s << " val: " << root->val;
    auto it = st.find(s);
    if (it == st.end()) {
      st[s] = 1;
    } else {
      if (it->second == 1) {
        // LOG(INFO) << "find " << root;
        ans.push_back(root);
      }
      it->second += 1;
    }
    return s;
  }
};
