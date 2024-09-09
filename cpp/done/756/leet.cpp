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

using cpair = pair<char, char>;
class Solution {
 public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    map<cpair, set<char>> transform;
    for (auto& item : allowed) {
      transform[cpair{item[0], item[1]}].insert(item[2]);
    }
    return helper(bottom, transform);
  }
  bool helper(string& bottom, const map<cpair, set<char>>& transform) {
    if (bottom.size() == 1) return true;
    auto cans = create(bottom, transform);
    // LOG(INFO) << "bottom: " << bottom << ", cans:" << cans;
    for (auto& s : cans) {
      if (helper(s, transform)) {
        return true;
      }
    }
    return false;
  }
  vector<string> create(string& from, const map<cpair, set<char>>& transform) {
    if (from.size() == 1) return vector<string>{""};
    vector<string> ret;
    const auto it = transform.find(cpair{from[0], from[1]});
    if (it == transform.end()) {
      return ret;
    }
    string temp = from.substr(1);
    auto suffixes = create(temp, transform);

    for (const auto& ch : it->second) {
      for (auto& suf : suffixes) {
        ret.emplace_back(ch + suf);
      }
    }
    return ret;
  }
};
