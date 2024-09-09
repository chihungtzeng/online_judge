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
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string preorder;
    preorder_traversal(root, preorder);
    if (!preorder.empty() && preorder.back() == ',') preorder.pop_back();
    return preorder;
  }

  void preorder_traversal(TreeNode* root, string& s) {
    if (!root) return;
    s += std::to_string(root->val);
    s.push_back(',');
    preorder_traversal(root->left, s);
    preorder_traversal(root->right, s);
  }

  vector<int> split(string s) {
    istringstream iss(s);
    vector<int> ret;
    string token;
    while (getline(iss, token, ',')) {
      ret.push_back(stoi(token));
    }
    return ret;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    vector<int> vals = split(data);
    return deserialize(vals);
  }
  TreeNode* deserialize(vector<int>& vals) {
    if (vals.empty()) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    vector<int> lvals, rvals;
    for (int i = 1; i < vals.size(); i++) {
      if (vals[i] < vals[0])
        lvals.push_back(vals[i]);
      else
        rvals.push_back(vals[i]);
    }
    root->left = deserialize(lvals);
    root->right = deserialize(rvals);
    return root;
  }
};
