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
    for (auto c : children) {
      if (c) delete c;
    }
  }
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(Node* root) {
    if (!root) return "{}";
    string ret = "{" + to_string(root->val);
    for (auto child : root->children) {
      ret += serialize(child);
    }
    ret += "}";
    return ret;
  }

  // Decodes your encoded data to tree.
  Node* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    return helper(string_view(data));
  }

  Node* helper(string_view sv) {
    if (sv == "{}") return nullptr;

    sv = sv.substr(1, sv.size() - 2);
    auto pos = sv.find('{');
    Node* root = new Node(stoi(string(sv.substr(0, pos))));
    int balance = 0;
    int left = pos;
    for (int i = left; i < sv.size(); i++) {
      if (sv[i] == '{')
        balance++;
      else if (sv[i] == '}')
        balance--;

      if (balance == 0) {
        root->children.push_back(helper(sv.substr(left, i - left + 1)));
        left = i + 1;
      }
    }
    return root;
  }
};

