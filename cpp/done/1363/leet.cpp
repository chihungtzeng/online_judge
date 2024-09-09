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
  string largestMultipleOfThree(vector<int>& digits) {
    vector<int> cnt(10);
    int sum = 0;
    for (int i = digits.size() - 1; i >= 0; i--) {
      cnt[digits[i]]++;
      sum += digits[i];
    }
    if (sum % 3 == 1) {
      rm(cnt, 1, 1) || rm(cnt, 2, 2);
    } else if (sum % 3 == 2) {
      rm(cnt, 2, 1) || rm(cnt, 1, 2);
    }
    return tostr(cnt);
  }
  bool rm(vector<int>& cnt, int target, int nrm) {
    const vector<int> t1{1, 4, 7}, t2{2, 5, 8};
    vector<int> ds;
    if (target == 1) {
      if (cnt[1] + cnt[4] + cnt[7] < nrm) return false;
      ds = t1;
    } else if (target == 2) {
      if (cnt[2] + cnt[5] + cnt[8] < nrm) return false;
      ds = t2;
    }
    int ndel = 0;
    for (int i = 0; i <= 9 && ndel < nrm; i++) {
      for (int j = 0; j < 3 && ndel < nrm; j++) {
        while (i == ds[j] && cnt[i] > 0 && ndel < nrm) {
          cnt[i]--;
          ndel++;
        }
      }
    }
    return true;
  }
  string tostr(vector<int>& cnt) {
    string ans;
    for (int i = 9; i >= 0; i--) {
      if (cnt[i] > 0) {
        ans += string(cnt[i], i + '0');
      }
    }
    if (ans[0] == '0') return "0";
    return ans;
  }
};
