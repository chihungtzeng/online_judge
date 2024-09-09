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
  string customSortString(string S, string T) {
    vector<int> t_cnt(26);
    for (auto ch : T) {
      t_cnt[ch - 'a']++;
    }
    string ret;
    for (auto ch : S) {
      if (t_cnt[ch - 'a'] > 0) {
        ret.append(string(t_cnt[ch - 'a'], ch));
        t_cnt[ch - 'a'] = 0;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (t_cnt[i] > 0) {
        ret.append(string(t_cnt[i], i + 'a'));
      }
    }
    return ret;
  }
};
