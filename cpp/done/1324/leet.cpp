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
  vector<string> printVertically(string s) {
    stringstream ss;
    string token;
    vector<string> tokens;
    ss << s;
    while (getline(ss, token, ' ')) {
      tokens.emplace_back(token);
    }
    const int nwords = tokens.size();
    int maxlen = 0;
    for (auto& t : tokens) {
      maxlen = max(maxlen, (int)t.size());
    }
    vector<string> ans(maxlen);
    for (int i = 0; i < maxlen; i++) {
      for (int j = 0; j < nwords; j++) {
        if (i < tokens[j].size()) {
          ans[i].push_back(tokens[j][i]);
        } else {
          ans[i].push_back(' ');
        }
      }
    }
    for (int i = 0; i < maxlen; i++) {
      while (ans[i].back() == ' ') ans[i].pop_back();
    }
    return ans;
  }
};
