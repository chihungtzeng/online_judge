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
  int n_;
  vector<int> choosable_;
  vector<int> blacklist_;
  Solution(int N, vector<int>& blacklist) : n_(N) {
    srand(time(NULL));
    sort(blacklist.begin(), blacklist.end());
    if (blacklist.size() > N / 2) {
      choosable_.reserve(N - blacklist.size());
      int j = 0;
      for (int i = 0; i < N; i++) {
        if (j < blacklist.size() && i == blacklist[j]) {
          j++;
        } else {
          choosable_.push_back(i);
        }
      }
    } else {
      blacklist_ = vector<int>(blacklist.begin(), blacklist.end());
    }
  }

  int pick() {
    if (!choosable_.empty()) {
      int idx = rand() % choosable_.size();
      return choosable_[idx];
    }
    bool done = false;
    int r;
    while (!done) {
      r = rand() % n_;
      if (!binary_search(blacklist_.begin(), blacklist_.end(), r)) {
        done = true;
      }
    }
    return r;
  }
};
