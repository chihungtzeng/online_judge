#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

constexpr int msb_pos = 30;
struct TrieNode {
  TrieNode *left, *right;
  TrieNode() : left(nullptr), right(nullptr) {}
  ~TrieNode() {
    if (left) delete left;
    if (right) delete right;
    left = nullptr;
    right = nullptr;
  }
};
class Solution {
 public:
  int findMaximumXOR(vector<int> &nums) {
    TrieNode *root = new TrieNode();
    int ans = 0;
    for (auto num : nums) {
      auto cur = root;
      for (int i = msb_pos; i >= 0; i--) {
        int val = (num >> i) & 1;
        if (val == 0) {
          if (!cur->left) {
            cur->left = new TrieNode();
          }
          cur = cur->left;
        } else {
          if (!cur->right) {
            cur->right = new TrieNode();
          }
          cur = cur->right;
        }
      }
      cur = root;
      int xorv = 0;
      for (int i = msb_pos; i >= 0; i--) {
        int val = (num >> i) & 1;
        //        LOG(INFO) << "val: " << val << " cur: " << cur << " cur->left:
        //        " << cur->left << " cur->right: " << cur->right << " xorv: "
        //        << xorv;
        if (val == 0 && cur->right) {
          xorv += (1 << i);
          cur = cur->right;
        } else if (val == 1 && cur->left) {
          xorv += (1 << i);
          cur = cur->left;
        } else if (val == 0) {
          cur = cur->left;
        } else {
          cur = cur->right;
        }
      }
      ans = max(ans, xorv);
    }
    /* To make no TLE
    if (root) {
      delete root;
    }
    */
    return ans;
  }
};
