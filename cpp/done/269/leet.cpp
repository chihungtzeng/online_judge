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
  string alienOrder(vector<string>& words) {
    vector<set<char>> kids(128), parents(128);
    vector<int> seen(128);
    vector<int> outdegrees(128);
    int nelem = 0;

    string prev_word = "";

    for (auto& w : words) {
      for (auto ch : w) {
        if (!seen[ch]) {
          seen[ch] = 1;
          nelem += 1;
        }
      }
    }

    for (auto& w : words) {
      int bound = min(w.size(), prev_word.size());
      for (int i = 0; i < bound; i++) {
        auto src = w[i];
        auto dst = prev_word[i];
        if (src != dst) {
          //LOG(INFO) << dst << " < " << src;
          kids[src].insert(dst);
          parents[dst].insert(src);
          break;
        }
        if (i == bound - 1 && w.size() < prev_word.size()) {
          return "";
        }
      }
      prev_word = w;
    }
    deque<char> q;
    for (char i = 'a'; i <= 'z'; i++) {
      if (seen[i]) {
        outdegrees[i] = kids[i].size();
        if (outdegrees[i] == 0) {
          //LOG(INFO) << "push " << i;
          q.push_back(i);
        }
      }
    }
#if DEBUG
    for (char dst = 'a'; dst <= 'z'; dst++) {
      if (!seen[dst]) continue;
      cout << dst << " : ";
      for (auto nbr : parents[dst]) {
        cout << nbr << " ";
      }
      cout << "outdegree: " << outdegrees[dst];
      cout << endl;
    }
#endif

    string ans;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop_front();
      ans += cur;
      for (auto p : parents[cur]) {
        outdegrees[p] -= 1;
        if (outdegrees[p] == 0) {
          q.push_back(p);
        }
      }
    }
    //LOG(INFO) << ans;
    if (ans.size() != nelem)
      return "";
    else
      return ans;
  }
};
