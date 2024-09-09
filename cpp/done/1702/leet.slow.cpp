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
  string maximumBinaryString(string s) {
    const int n = s.size();
    const int n_1 = n - 1;
    int i = 0, j = n - 2;
    while (i <= j && i < n && j >= 0) {
      while (i < n_1 && ((s[i] == '0' && s[i + 1] == '0') || (s[i] == '1'))) {
        s[i] = '1';
        i++;
      }
      if (j > i && (s[j] == '1' && s[j + 1] == '0')) {
        s[j] = '0';
        s[j + 1] = '1';
      }
      j--;
    }
    return s;
  }
};
