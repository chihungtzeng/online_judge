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
  int maxScoreWords(vector<string>& words, vector<char>& letters,
                    vector<int>& score) {
    vector<int> lcnt(26);
    for (auto ch : letters) {
      lcnt[ch - 'a']++;
    }
    return dfs(words, lcnt, score, 0);
  }

  int dfs(vector<string>& words, vector<int>& lcnt, vector<int>& score,
          int idx) {
    if (idx == words.size()) return 0;
    int ans = dfs(words, lcnt, score, idx + 1);

    if (can_form_word(words[idx], lcnt)) {
      int cur_score = 0;
      for (auto ch : words[idx]) {
        lcnt[ch - 'a']--;
        cur_score += score[ch - 'a'];
      }
      ans = max(ans, cur_score + dfs(words, lcnt, score, idx + 1));
      for (auto ch : words[idx]) {
        lcnt[ch - 'a']++;
      }
    }
    return ans;
  }

  bool can_form_word(string& word, vector<int>& lcnt) {
    vector<int> cnt(26);
    for (auto ch : word) {
      cnt[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > lcnt[i]) return false;
    }
    return true;
  }
};
