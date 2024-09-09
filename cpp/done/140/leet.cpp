#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    unordered_map<string, vector<string>> cache;

    return wordBreak2(s, wordDict, cache);
  }
  vector<string> wordBreak2(const string& s, vector<string> &wordDict, unordered_map<string, vector<string>>& cache) {
    vector<string> ret;
    if (s.length() == 0) {
      return ret;
    }

    if (cache.find(s) != cache.end())
    {
      return cache[s];
    }

    ret.reserve(16);
    for (const auto &w : wordDict) {
      if (s == w) {
        ret.emplace_back(w);
        continue;
      }
      if (s.compare(0, w.length(), w) != 0) {
        continue;
      }
      for (const auto &suffix : wordBreak2(s.substr(w.length()), wordDict, cache)) {
        ret.emplace_back(w + ' ' + suffix);
      }
    }
    cache[s] = ret;
    return ret;
  }
};
