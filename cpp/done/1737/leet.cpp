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

constexpr int nchar = 26;
class Solution {
 public:
  int minCharacters(string s1, string s2) {
    auto freq1 = count(s1);
    auto freq2 = count(s2);
    vector<int> psum1 = freq1, psum2 = freq2;
    for (int i = 1; i < nchar; i++) {
      psum1[i] += psum1[i - 1];
      psum2[i] += psum2[i - 1];
    }

    int ans = INT_MAX;
    for (int i = 0; i < 26; i++) {
      ans = min(ans, psum1.back() - freq1[i] + psum2.back() - freq2[i]);
    }
    ans = min(ans, op1(psum1, psum2));
    ans = min(ans, op1(psum2, psum1));
    return ans;
  }
  int op1(vector<int>& psum1, vector<int>& psum2) {
    int res = INT_MAX;
    //    LOG(INFO) << "psum1: " << psum1;
    //    LOG(INFO) << "psum2: " << psum2;
    for (int i = 0; i < 25; i++) {
      int can1 = range_sum(psum1, i + 1, nchar - 1);
      int can2 = range_sum(psum2, 0, i);
      //      LOG(INFO) << "max to " << char('a'+i) << " can1: " << can1 << "
      //      can2: " << can2;
      res = min(res, can1 + can2);
    }
    return res;
  }

  int range_sum(vector<int>& psum, int from, int to) {
    if (to < 0 || from > to) return 0;
    if (from == 0) {
      return psum[to];
    } else {
      return psum[to] - psum[from - 1];
    }
  }
  vector<int> count(string& s) {
    vector<int> freq(nchar);
    for (auto ch : s) {
      freq[ch - 'a']++;
    }
    return freq;
  }
};
