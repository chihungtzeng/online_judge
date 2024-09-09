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

class Solution {
 public:
  int beautySum(string s) {
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      s[i] -= 'a';
    }
    for (int i = 0; i < n; i++) {
      vector<int> cnt(26);
      multiset<int> cnt_ms;
      cnt[s[i]] = 1;
      cnt_ms.insert(1);
      for (int j = i + 1; j < n; j++) {
        if (cnt[s[j]] > 0) {
          auto it = cnt_ms.find(cnt[s[j]]);
          cnt_ms.erase(it);
        }
        cnt[s[j]]++;
        cnt_ms.insert(cnt[s[j]]);
        ans += *cnt_ms.rbegin() - *cnt_ms.begin();
      }
    }
    return ans;
  }
};
