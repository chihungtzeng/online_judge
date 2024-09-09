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
  string reformat(const string s) {
    vector<vector<char>> chs(2);
    for (auto ch : s) {
      if (isdigit(ch))
        chs[0].push_back(ch);
      else
        chs[1].push_back(ch);
    }
    int cur = 0;

    if (chs[1].size() > chs[0].size()) cur = 1;
    if (chs[cur].size() - chs[1 - cur].size() > 1) return "";

    string ret;
    while (chs[0].size() > 0 || chs[1].size() > 0) {
      ret.push_back(chs[cur].back());
      chs[cur].pop_back();
      cur = 1 - cur;
    }
    return ret;
  }
};
