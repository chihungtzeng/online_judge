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
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> mp;
    for (auto& path : paths) {
      auto tokens = parse(path);
      for (int i = 1; i < tokens.size(); i++) {
        int pos = tokens[i].find('(');
        string filename = tokens[i].substr(0, pos);
        string digest = tokens[i].substr(pos + 1, tokens[i].size() - 1);
        mp[digest].emplace_back(tokens[0] + '/' + filename);
      }
    }
    vector<vector<string>> ret;
    for (auto& [key, val] : mp) {
      if (val.size() >= 2) {
        ret.push_back(val);
      }
    }
    return ret;
  }
  vector<string> parse(string& path) {
    istringstream ss(path);
    string token;
    vector<string> ret;
    while (getline(ss, token, ' ')) {
      ret.emplace_back(token);
    }
    return ret;
  }
};
