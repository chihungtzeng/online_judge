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
  bool checkIfCanBreak(string s1, string s2) {
    vector<int> cnt1(26), cnt2(26);
    for (auto ch : s1) cnt1[ch - 'a']++;
    for (auto ch : s2) cnt2[ch - 'a']++;

    if (can_break(cnt1, cnt2) || can_break(cnt2, cnt1)) return true;
    return false;
  }
  bool can_break(vector<int> cnt1, vector<int> cnt2) {
    int i = 0, j = 0;
    while (i < 26 && j < 26) {
//      LOG(INFO) << "i: " << i << " j: " << j;
      while (i < 26 && cnt1[i] == 0) i++;
      while (j < 26 && cnt2[j] == 0) j++;
      if (i >= 26 || j>=26) break;
      if (i >= j) {
        int nelem = min(cnt1[i], cnt2[j]);
        cnt1[i] -= nelem;
        cnt2[j] -= nelem;
      } else {
        return false;
      }
    }
    return true;
  }
};
