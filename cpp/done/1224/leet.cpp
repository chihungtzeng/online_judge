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
#define DEBUG 0

class Solution {
 public:
  int maxEqualFreq(vector<int>& nums) {
    unordered_map<int, int> cnt, cnt2;
    const int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int val = nums[i];
      auto it = cnt2.find(cnt[val]);
      if (it != cnt2.end()) {
        if (it->second == 1)
          cnt2.erase(it);
        else
          it->second -= 1;
      }
      cnt[val]++;
      cnt2[cnt[val]]++;
#if DEBUG
      LOG(INFO) << "pos " << i << " val: " << val;
      cout << "cnt :";
      for (auto& [k, v] : cnt) {
        cout << " " << k << ":" << v;
      }
      cout << endl;
      cout << "cnt2:";
      for (auto& [k, v] : cnt2) {
        cout << " " << k << ":" << v;
      }
      cout << endl;
#endif
      if (is_valid_prefix(cnt, cnt2, val)) {
#if DEBUG
        LOG(INFO) << "valid prefix at pos " << i << " val: " << val;
#endif
        ans = i + 1;
      }
    }
    return ans;
  }
  bool is_valid_prefix(unordered_map<int, int>& cnt,
                       unordered_map<int, int>& cnt2, const int val) {
    if (cnt2.size() >= 3) return false;
    int gs1 = cnt[val];
    if (cnt2.size() == 1) {
      return gs1 == 1 || cnt2[gs1] == 1;
    }
    int gs2 = INT_MAX;
    for (auto& [k, v] : cnt2) {
      if (k != gs1) gs2 = k;
    }
    if (cnt2[gs1] == 1 && gs1 - 1 == gs2) return true;
    if (cnt2[gs2] == 1 && gs2 - 1 == gs1) return true;
    if (gs1 == 1 && cnt2[gs1] == 1) return true;
    if (gs2 == 1 && cnt2[gs2] == 1) return true;

    return false;
  }
};
