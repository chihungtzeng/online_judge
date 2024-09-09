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
  string reorganizeString(string s) {
    vector<int> cnt(26);
    for (auto ch : s) {
      cnt[ch - 'a']++;
    }
    auto it = max_element(cnt.begin(), cnt.end());
    int bound = (s.size() % 2 == 0) ? s.size() / 2 : s.size() / 2 + 1;
    if (*it > bound) return "";
    auto cmp = [](const auto& a, const auto& b) { return a.first < b.first; };
    using icpair = pair<int, char>;
    priority_queue<icpair, vector<icpair>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < 26; i++) {
      if (cnt[i] > 0) pq.push(icpair{cnt[i], i + 'a'});
    }
    string ans;
    while (!pq.empty()) {
      if (pq.size() >= 2) {
        icpair most[2];
        for (int i = 0; i < 2; i++) {
          most[i] = pq.top();
          pq.pop();
        }
        ans.push_back(most[0].second);
        ans.push_back(most[1].second);
        for (int i = 0; i < 2; i++) {
          most[i].first -= 1;
          if (most[i].first > 0) {
            pq.push(most[i]);
          }
        }
      } else {
        auto most0 = pq.top();
        pq.pop();
        for (int i = 0; i < most0.first; i++) {
          ans.push_back(most0.second);
        }
      }
    }
    return ans;
  }
};
