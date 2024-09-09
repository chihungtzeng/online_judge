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

using cipair = pair<char, int>;
class Solution {
 public:
  int maxRepOpt1(string text) {
    vector<cipair> pairs;
    int len = 0;
    char prev_ch = 0;
    for (auto ch : text) {
      if (prev_ch == ch) {
        len++;
      } else {
        if (len > 0) {
          pairs.push_back({prev_ch, len});
        }
        prev_ch = ch;
        len = 1;
      }
    }
    if (len > 0) {
      pairs.push_back({prev_ch, len});
    }
    int ans = 0;

    vector<int> cnt(26);
    for (int i = 0; i < pairs.size(); i++) {
      cnt[pairs[i].first - 'a']++;
    }

    for (int i = 0, stop = pairs.size() - 2; i < stop; i++) {
      if (pairs[i].first == pairs[i + 2].first) {
        if (pairs[i + 1].second == 1) {
          if (cnt[pairs[i].first - 'a'] >= 3) {
            ans = max(ans, pairs[i].second + pairs[i + 2].second + 1);
          } else {
            ans = max(ans, pairs[i].second + pairs[i + 2].second);
          }
        } else {
          ans = max(ans, pairs[i].second + 1);
          ans = max(ans, pairs[i + 2].second + 1);
        }
      } else {
        ans = max(ans, pairs[i].second);
      }
    }
    for (int i = 0; i < pairs.size(); i++) {
      if (cnt[pairs[i].first - 'a'] > 1) {
        ans = max(ans, pairs[i].second + 1);
      } else {
        ans = max(ans, pairs[i].second);
      }
    }
    return ans;
  }
};
