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
  string sortString(string s) {
    vector<int> cnt(26);
    for (auto ch : s) {
      cnt[ch - 'a']++;
    }
    string ans;

    while (ans.size() < s.size()) {
      int i = 0;
      while (i < 26 && cnt[i] == 0) i++;
      if (i < 26) {
        ans.push_back(i + 'a');
        cnt[i]--;
        i++;
      }
      while (i < 26) {
        while (i < 26 && cnt[i] == 0) i++;
        if (i < 26) {
          ans.push_back(i + 'a');
          cnt[i]--;
          i++;
        }
      }
      i = 25;
      while (i >= 0 && cnt[i] == 0) i--;
      if (i >= 0) {
        ans.push_back(i + 'a');
        cnt[i]--;
        i--;
      }
      while (i >= 0) {
        while (i >= 0 && cnt[i] == 0) i--;
        if (i >= 0) {
          ans.push_back(i + 'a');
          cnt[i]--;
          i--;
        }
      }
    }
    return ans;
  }
};
