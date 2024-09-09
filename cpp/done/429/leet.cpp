#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
  ~Node() {
    for (int i = 0; i < children.size(); i++) {
      delete children[i];
    }
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ret;
    if (!root) {
      return ret;
    }
    deque<pair<Node*, int>> q;

    q.push_back({root, 0});
    while (!q.empty()) {
      auto item = q.front();
      q.pop_front();
      auto cur = item.first;
      auto level = item.second;
      if (level == ret.size()) {
        ret.push_back({cur->val});
      } else {
        ret[level].push_back(cur->val);
      }
      for (auto c : cur->children) {
        q.push_back({c, level + 1});
      }
    }

    return ret;
  }
};
