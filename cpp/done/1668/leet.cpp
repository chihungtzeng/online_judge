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
  int maxRepeating(string sequence, string word) {
    const int wlen = word.size();
    const int n = sequence.size();
    int ans = 0;
    string_view sv(sequence);
    string_view wv(word);

    int rep = 0;
    for (int i = 0; i + wlen - 1 < n;) {
      string_view temp = sv.substr(i, wlen);
      if (temp == wv) {
        rep++;
        i += wlen;
      } else {
        ans = max(ans, rep);
        rep = 0;
        i++;
      }
    }
    ans = max(ans, rep);
    return ans;
  }
};
