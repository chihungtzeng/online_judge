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

class MyCalendar {
 public:
  map<int, int> ends_;
  MyCalendar() {}

  bool book(int start, int end) {
    auto it = ends_.upper_bound(start);
    if (it != ends_.end() && it->second < end) {
      return false;
    }
    ends_[end] = start;
    return true;
  }
};
