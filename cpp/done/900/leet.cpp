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
class RLEIterator {
 public:
  vector<pair<int, int>> elems_;
  int cursor_;
  RLEIterator(vector<int>& A) {
    elems_.resize(A.size() >> 1);
    for (int i = 0; i < A.size(); i += 2) {
      elems_[i / 2] = {A[i], A[i + 1]};
    }
    cursor_ = 0;
  }

  int next(int n) {
    while (cursor_ < elems_.size() and elems_[cursor_].first < n) {
      n -= elems_[cursor_].first;
      elems_[cursor_].first = 0;
      cursor_++;
    }
    if (cursor_ == elems_.size()) return -1;
    elems_[cursor_].first -= n;
    return elems_[cursor_].second;
  }
};
