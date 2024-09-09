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
  int expressiveWords(string s, vector<string>& words) {
    auto spairs = parse(s);
    int ans = 0;
    // LOG(INFO) << s << ": " << spairs;
    for (int i = words.size() - 1; i >= 0; i--) {
      auto wpairs = parse(words[i]);
      if (wpairs.size() != spairs.size()) continue;

      // LOG(INFO) << words[i] << ": " << wpairs;
      bool match = true;
      for (int j = 0; match && j < wpairs.size(); j++) {
        if (spairs[j].first != wpairs[j].first) {
          match = false;
        }
        if (spairs[j].second <= 2) {
          if (spairs[j].second != wpairs[j].second) {
            match = false;
          }
        } else {
          if (spairs[j].second < wpairs[j].second) {
            match = false;
          }
        }
      }
      if (match) ans++;
    }
    return ans;
  }
  vector<pair<char, int>> parse(string& s) {
    vector<pair<char, int>> spairs;
    for (int i = 0; i < s.size(); i++) {
      int j = i + 1;
      while (j < s.size() && s[j] == s[i]) {
        j++;
      }
      spairs.push_back({s[i], j - i});
      i = j - 1;
    }
    return spairs;
  }
};
