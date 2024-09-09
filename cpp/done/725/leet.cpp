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
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
 public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    vector<ListNode*> ans(k);
    if (!root) return ans;
    int n = 0;
    ListNode *cur = root, *prev = nullptr;
    while (cur) {
      n++;
      cur = cur->next;
    }
    int avg = n / k;
    int nremains = n - k * avg;
    cur = root;
    for (int i = 0; i < k; i++) {
      ans[i] = cur;
      int step = avg;
      if (nremains > 0) {
        step++;
        nremains--;
      }
      while (step--) {
        prev = cur;
        cur = cur->next;
      }
      if (prev) prev->next = nullptr;
    }
    return ans;
  }
};
