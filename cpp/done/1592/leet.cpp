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
  string reorderSpaces(string text) {
    string token;
    vector<string> tokens;
    stringstream ss;
    ss << text;
    while (getline(ss, token, ' ')) {
      if (token.size() > 0) tokens.emplace_back(token);
    }
    int nspaces = text.size();
    for (auto& t : tokens) {
      nspaces -= t.size();
    }
    int q = 0, r = 0;
    if (tokens.size() == 1) {
      q = 0;
      r = nspaces;
    } else {
      q = nspaces / (tokens.size() - 1);
      r = nspaces - q * (tokens.size() - 1);
    }
    string ans = tokens[0];
    for (int i = 1; i < tokens.size(); i++) {
      ans += string(q, ' ');
      ans += tokens[i];
    }
    ans += string(r, ' ');
    return ans;
  }
};

