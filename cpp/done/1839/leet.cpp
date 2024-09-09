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

const string vowels = "aeiou";
class Solution {
 public:
  int longestBeautifulSubstring(string word) {
    const int n = word.size();
    int ans = 0;
    vector<int> cnt(26);
    for (int start = 0; start < n; start++) {
      if (word[start] != 'a') {
        continue;
      }
      for (auto ch : vowels) {
        cnt[ch - 'a'] = 0;
      }

      char last = 0;
      int end = start;
      while (word[end] >= last && end < n) {
        cnt[word[end] - 'a']++;
        last = word[end];
        end++;
      }
      if (satisfy(cnt)) {
        ans = max(ans, end - start);
      }
      //      LOG(INFO) << pair<int,int>{start, end} << ": " << satisfy(cnt);
      start = end - 1;
    }
    return ans;
  }
  bool satisfy(vector<int>& cnt) {
    for (auto ch : vowels) {
      if (cnt[ch - 'a'] == 0) return false;
    }
    return true;
  }
};
