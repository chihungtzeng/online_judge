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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() {
    if (next) delete next;
  }
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  ~TreeNode() {
    if (left) delete left;
    if (right) delete right;
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    if (!head) {
      return true;
    }
    if (!root) {
      return false;
    }
    return dfs(head, root) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }
  bool dfs(ListNode *head, TreeNode *root) {
    if (!head) {
      return true;
    }
    if (!root) {
      return false;
    }
#if 1
    if (head->val != root->val) return false;
    return dfs(head->next, root->left) || dfs(head->next, root->right);
#else
    return (head->val != root->val) &&
           (dfs(head->next, root->left) || dfs(head->next, root->right));
#endif
  }
};
