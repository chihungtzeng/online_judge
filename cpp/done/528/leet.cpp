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
  Solution(vector<int>& w): psum(w.size()) {
    psum[0] = w[0];
    for (int i = 1; i < w.size(); i++) {
      psum[i] = psum[i - 1] + w[0];
    }
    srand(time(nullptr));
  }

  int pickIndex() {
    int pick = 1 + rand() % psum.back();
    auto it = upper_bound(psum.begin(), psum.end(), pick);
    int idx = (it - psum.begin()) - 1;
    LOG(INFO) << idx;
    return idx;
  }
};
