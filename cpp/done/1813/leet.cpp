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
  bool areSentencesSimilar(string sentence1, string sentence2) {
    auto toks1 = parse(sentence1);
    auto toks2 = parse(sentence2);
    // LOG(INFO) << toks1  << " v.s. " << toks2;
    bool done = false;
    if (toks1.size() > toks2.size()) {
      swap(toks1, toks2);
    }
    while (!toks1.empty() && toks1.front() == toks2.front()) {
      toks1.pop_front();
      toks2.pop_front();
    }
    while (!toks1.empty() && toks1.back() == toks2.back()) {
      toks1.pop_back();
      toks2.pop_back();
    }

    return toks1.empty();
  }
  deque<string> parse(const string& s) {
    deque<string> ret;
    string token;
    istringstream ss(s);
    while (getline(ss, token, ' ')) {
      ret.push_back(token);
    }
    return ret;
  }
};
