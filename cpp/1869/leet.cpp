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
  bool checkZeroOnes(string s) {
    int len = 0;
    vector<int> ell(2);
    char prev = 0;
    for (char ch : s) {
      if (ch != prev && prev != 0) {
        ell[prev - '0'] = max(ell[prev - '0'], len);
        len = 1;
      } else {
        len++;
      }
      prev = ch;
    }
    if (len > 0) {
      ell[prev - '0'] = max(ell[prev - '0'], len);
    }
    return bool(ell[1] > ell[0]);
  }
};
