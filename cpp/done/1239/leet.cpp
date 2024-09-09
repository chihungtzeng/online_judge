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

class Solution {
 public:
  int maxLength(vector<string>& arr) {
    vector<bool> used(256, false);
    vector<string> ss;
    for (auto& s : arr) {
      if (has_uniq_chars(s)) ss.push_back(s);
    }
    return helper(ss, 0, used);
  }

  bool has_uniq_chars(string& s) {
    vector<bool> vis(26, false);
    for (auto ch : s) {
      int idx = ch - 'a';
      if (vis[idx]) return false;
      vis[idx] = true;
    }
    return true;
  }
  int helper(vector<string>& arr, int pos, vector<bool>& used) {
    if (pos == arr.size()) return 0;
    bool can_pick = true;
    for (auto ch : arr[pos]) {
      if (used[ch]) {
        can_pick = false;
        break;
      }
    }
    int ans = helper(arr, pos + 1, used);
    if (can_pick) {
      for (auto ch : arr[pos]) {
        used[ch] = true;
      }
      ans = max(ans,
                static_cast<int>(arr[pos].size()) + helper(arr, pos + 1, used));
      for (auto ch : arr[pos]) {
        used[ch] = false;
      }
    }
    return ans;
  }
};
