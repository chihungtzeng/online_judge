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
  string mostCommonWord(string para, vector<string>& banned) {
    auto word_freq = parse(para);
#if 0    
    for (auto& [s, freq] : word_freq) {
      LOG(INFO) << s << " : " << freq;
    }
#endif
    for (auto& w : banned) {
      word_freq.erase(w);
    }
    int best = 0;
    string ans;
    for (auto& [s, freq] : word_freq) {
      if (freq > best) {
        best = freq;
        ans = s;
      }
    }
    return ans;
  }

  unordered_map<string, int> parse(string& para) {
    unordered_map<string, int> res;
    string token;
    for (auto ch : para) {
      char tch = isletter(ch);
      if (tch) {
        token.push_back(tch);
      } else if (!token.empty()) {
        res[token] += 1;
        token.clear();
      }
    }
    if (!token.empty()) res[token] += 1;
    return res;
  }
  char isletter(char ch) {
    if (ch >= 'a' && ch <= 'z')
      return ch;
    else if (ch >= 'A' && ch <= 'Z')
      return ch - 'A' + 'a';
    else
      return '\0';
  }
};
