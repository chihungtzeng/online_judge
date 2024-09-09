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

class Solution {
 public:
  int maximumRemovals(string s, string p, vector<int>& removable) {
    int left = 0, right = removable.size();
    int ans = 0;
    string temp;
    while (left <= right) {
      int mid = (left + right) >> 1;
      temp = s;
      for (int i = 0; i < mid; i++) {
        temp[removable[i]] = '!';
      }
      if (is_subsequenece(temp, p)) {
        ans = max(ans, mid);
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
  bool is_subsequenece(string& s1, string& s2) {
    const int n1 = s1.size(), n2 = s2.size();
    int j = 0;
    for (int i = 0; i < n1; i++) {
      if (s1[i] == s2[j]) {
        j++;
      }
      if (j == n2) return true;
    }
    return false;
  }
};
