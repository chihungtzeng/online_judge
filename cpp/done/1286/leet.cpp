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

class CombinationIterator {
 public:
  const int ncomb_;
  string chs_;
  const int n_;
  vector<int> picks_;
  bool transit_;

  CombinationIterator(string characters, int combinationLength)
      : ncomb_(combinationLength),
        chs_(characters),
        n_(characters.size()),
        picks_(n_) {
    for (int i = 0; i < ncomb_; i++) {
      picks_[i] = 1;
    }
    transit_ = true;
  }

  string next() {
    string ret;
    for (int i = 0; i < n_; i++) {
      if (picks_[i]) {
        ret.push_back(chs_[i]);
      }
    }
    bool has0 = false;
    int pos0 = 0;
    int n1 = 0;
    transit_ = false;
    for (int i = n_ - 1; i >= 0; i--) {
      if (picks_[i] == 0 && !has0) {
        has0 = true;
        pos0 = i;
      } else if (picks_[i] == 0 && has0) {
        pos0 = i;
      } else if (picks_[i] == 1 && has0) {
        swap(picks_[i], picks_[pos0]);
        transit_ = true;
        break;
      } else {
        n1++;
      }
    }
    if (n1 > 0) {
      for (int i = pos0 + 1; i < n_; i++) {
        if (n1) {
          picks_[i] = 1;
          n1--;
        } else {
          picks_[i] = 0;
        }
      }
    }
    // LOG(INFO) << picks_;
    return ret;
  }

  bool hasNext() { return transit_; }
};

