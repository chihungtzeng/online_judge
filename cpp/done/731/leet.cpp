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

class MyCalendarTwo {
 public:
  map<int, int> entries_;
  MyCalendarTwo() {}

  bool book(int start, int end) {
    entries_[start]++;
    entries_[end]--;
    int noverlap = 0;
    for (auto& [key, val] : entries_) {
      noverlap += val;
      if (noverlap > 2) {
        entries_[start]--;
        entries_[end]++;
        return false;
      }
    }
    return true;
  }
};
