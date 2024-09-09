#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> srows{"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
    vector<bool> hit[srows.size()];
    for (int i = 0; i < srows.size(); i++) {
      hit[i].resize(26);
      for (auto ch : srows[i]) {
        hit[i][ch - 'A'] = true;
      }
    }
    vector<string> ret;
    for (auto& w : words) {
      vector<int> rows(srows.size(), 0);
      for (auto ch : w) {
        auto code = (ch >= 'A' && ch <= 'Z') ? ch - 'A' : ch - 'a';
        for (int i = 0; i < srows.size(); i++) {
          if (hit[i][code]) {
            rows[i] = 1;
            break;
          }
        }
      }
      auto sum = accumulate(rows.begin(), rows.end(), 0);
      if (sum == 1) {
        ret.push_back(w);
      }
    }
    return ret;
  }
};
