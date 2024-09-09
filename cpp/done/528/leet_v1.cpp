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
  vector<int> psum;
  Solution(vector<int>& w) {
    psum = vector<int>(w.begin(), w.end());
    for (int i = 1; i < w.size(); i++) {
      psum[i] += psum[i - 1];
    }
    srand(time(NULL));
  }

  int pickIndex() {
    int pick = 1 + rand() % psum.back();
    auto it = lower_bound(psum.begin(), psum.end(), pick);
    return it - psum.begin();
  }
};
