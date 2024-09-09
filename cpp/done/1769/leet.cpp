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
  vector<int> minOperations(string boxes) {
    const int n = boxes.size();
    vector<int> ans(n);
    vector<int> pos;
    pos.reserve(n);
    for (int i = 0; i < n; i++) {
      if (boxes[i] == '1') {
        pos.push_back(i);
      }
    }
    ans[0] = accumulate(pos.begin(), pos.end(), 0);
    int ngeq = pos.size();
    int nle = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
      while (j < pos.size() && pos[j] < i) {
        j++;
        ngeq--;
        nle++;
      }
      ans[i] = ans[i - 1] - ngeq + nle;
    }
    return ans;
  }
};
