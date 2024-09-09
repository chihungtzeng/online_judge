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
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
};
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string ret;
    if (!root) return "{}";
    ret = to_string(root->val);
    ret.append(serialize(root->left));
    ret.append(serialize(root->right));
    return '{' + ret + '}';
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.size() <= 2) return nullptr;
    data = data.substr(1, data.size() - 2);
    int pos = data.find('{');
    string sval = data.substr(0, pos);
    TreeNode* root = new TreeNode(stoi(sval));
    int balance = 1;
    for (int i = pos + 1; i < data.size() && balance != 0; i++) {
      if (data[i] == '{') balance += 1;
      if (data[i] == '}') balance -= 1;
      if (balance == 0) {
        root->left = deserialize(data.substr(pos, i - pos + 1));
        root->right = deserialize(data.substr(i + 1));
      }
    }
    return root;
  }
};
