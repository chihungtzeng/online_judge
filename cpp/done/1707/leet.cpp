#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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

struct Trie {
  vector<Trie *> children;
  Trie() : children(2) {}
  ~Trie() {
    for (int i = 0; i < 2; i++) {
      if (children[i]) delete children[i];
    }
  }
  Trie *insert(int n) {
    if (n < 0 || n >= 2) return nullptr;
    if (!children[n]) {
      children[n] = new Trie();
    }
    return children[n];
  }
};

class Solution {
 public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    const int nq = queries.size();
    const int n = nums.size();
    for (int i = 0; i < nq; i++) {
      queries[i].push_back(i);
    }
    auto cmp_query = [](const auto &a, const auto &b) { return a[1] < b[1]; };
    sort(queries.begin(), queries.end(), cmp_query);
    sort(nums.begin(), nums.end());
    vector<int> ans(nq);
    int j = 0;
    Trie *root = new Trie();
    for (int i = 0; i < nq; i++) {
      //      LOG(INFO) << "handle query " << queries[i];
      while (j < n && nums[j] <= queries[i][1]) {
        //        LOG(INFO) << "insert " << nums[j] << " to trie";
        insert(root, nums[j]);
        j++;
      }
      if (j == 0) {
        ans[queries[i][2]] = -1;
      } else {
        ans[queries[i][2]] = max_xor(root, queries[i][0]);
      }
    }
    delete root;
    return ans;
  }
  void insert(Trie *root, int val) {
    Trie *cur = root;
    for (int i = 31; i >= 0; i--) {
      int bit = (val >> i) & 1;
      cur = cur->insert(bit);
    }
  }
  int max_xor(Trie *root, int val) {
    Trie *cur = root;
    int res = 0;
    for (int i = 31; i >= 0; i--) {
      int bit = 1 - ((val >> i) & 1);
      if (cur->children[bit]) {
        res = (res << 1) + 1;
        cur = cur->children[bit];
      } else {
        res = res << 1;
        cur = cur->children[1 - bit];
      }
    }
    return res;
  }
};
