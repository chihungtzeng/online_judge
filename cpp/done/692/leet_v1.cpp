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

using sipair = pair<string, int>;
class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> cnt;
    for (auto& w : words) {
      cnt[w] += 1;
    }
    auto cmp = [](const auto& a, const auto& b) {
      if (a.second != b.second) return a.second > b.second;
      return a.first < b.first;
    };
    priority_queue<sipair, vector<sipair>, decltype(cmp)> pq(cmp);
    for (auto& [s, freq] : cnt) {
      pq.push(sipair{s, freq});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<string> ret;
    while (!pq.empty()) {
      ret.emplace_back(pq.top().first);
      pq.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
