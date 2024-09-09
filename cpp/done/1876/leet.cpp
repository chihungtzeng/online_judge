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
  int countGoodSubstrings(string s) {
    multiset<char> cnt;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      cnt.insert(s[i]);

      if (i >= 2) {
        if (is_good(cnt)) {
          //          LOG(INFO) << "Good: " << s.substr(i-2, 3);
          ans++;
        } else {
          //        LOG(INFO) << "Bad: " << s.substr(i-2, 3);
        }
        auto it = cnt.find(s[i - 2]);
        cnt.erase(it);
      }
    }
    return ans;
  }
  bool is_good(const multiset<char>& cnt) {
    vector<int> freq(26);
    for (auto& ch : cnt) {
      freq[ch - 'a']++;
      if (freq[ch - 'a'] >= 2) {
        return false;
      }
    }
    return true;
  }
};
