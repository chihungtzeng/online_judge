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
  int findTheWinner(int n, int k) {
    deque<int> q(n);
    for (int i = 0; i < n; i++) {
      q[i] = i + 1;
    }
    int cur = 0;
    int last = -1;
    while (!q.empty()) {
      last = *q.begin();
      int idx2rm = (cur + k - 1) % q.size();
      //      LOG(INFO) << "rm " << idx2rm;
      q.erase(q.begin() + idx2rm);
      cur = idx2rm;
    }
    return last;
  }
};
