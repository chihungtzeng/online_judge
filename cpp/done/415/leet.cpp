#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
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
  string addStrings(string s1, string s2) {
    string out;
    out.reserve(max(s1.size(), s2.size()) + 1);
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0) {
      char c1 = (i >= 0) ? s1[i] : '0';
      char c2 = (j >= 0) ? s2[j] : '0';
      int sum = (c1 - '0') + (c2 - '0') + carry;
      //      LOG(INFO) << "c1: " << c1 << " c2: " << c2 << " carry: " << carry
      //      << " sum: " << sum;
      out.push_back((sum % 10) + '0');
      carry = sum / 10;
      i--;
      j--;
    }
    if (carry > 0) {
      out.push_back(carry + '0');
    }
    std::reverse(out.begin(), out.end());
    return out;
  }
};
