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
  bool closeStrings(string word1, string word2) {
    vector<int> cnt1(26), cnt2(26);
    if (word1.size() != word2.size()) return false;
    get_cnt(cnt1, word1);
    get_cnt(cnt2, word2);

    for (int i = 0; i < 26; i++) {
      if (cnt1[i] > 0 && cnt2[i] == 0) return false;
      if (cnt1[i] == 0 && cnt2[i] > 0) return false;
    }
    sort(cnt1.begin(), cnt1.end());
    sort(cnt2.begin(), cnt2.end());
    for (int i = 0; i < 26; i++) {
      if (cnt1[i] != cnt2[i]) return false;
    }
    return true;
  }

  void get_cnt(vector<int>& cnt, string& s) {
    for (auto ch : s) {
      cnt[ch - 'a']++;
    }
  }
};
