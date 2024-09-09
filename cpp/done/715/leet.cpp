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

using ipair = pair<int, int>;
class RangeModule {
 public:
  vector<ipair> segs;
  RangeModule() {}

  bool is_intersect(int l1, int r1, int l2, int r2) {
    int l3 = max(l1, l2);
    int r3 = min(r1, r2);
    return bool(l3 <= r3);
  }

  void addRange(int left, int right) {
    //LOG(INFO) << "before adding edge: " << segs << " to add " << ipair{left, right};
    vector<ipair> temp;
    for (auto [u, v] : segs) {
      if (is_intersect(u, v, left, right)) {
        left = min(left, u);
        right = max(right, v);
      } else {
        temp.push_back({u, v});
      }
    }
    int pos = -1;
    for (int i = 0; i < temp.size() && pos < 0; i++) {
      if (temp[i].first > right) {
        pos = i;
      }
    }
    if (pos < 0) {
      temp.push_back({left, right});
    } else {
      temp.insert(temp.begin() + pos, {left, right});
    }
    swap(temp, segs);
    // LOG(INFO) << "after adding edge: " << segs;
  }

  bool queryRange(int left, int right) {
    // LOG(INFO) << "query range";
    // LOG(INFO) << "query range " << segs;
    if (segs.empty()) return false;
    int l = 0, r = segs.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (segs[mid].first >= right) {
        r = mid - 1;
      } else if (segs[mid].second <= left) {
        l = mid + 1;
      } else {
        return bool(segs[mid].first <= left & segs[mid].second >= right);
      }
    }
    return false;
  }

  void removeRange(int left, int right) {
    vector<ipair> temp;
    for (auto [u, v] : segs) {
      if (is_intersect(u, v, left, right)) {
        if (u < left) {
          temp.push_back({u, left});
        }
        if (right < v) {
          temp.push_back({right, v});
        }
      } else {
        temp.push_back({u, v});
      }
    }
    swap(temp, segs);
    // LOG(INFO) << "after remove " << ipair{left, right} << " : " << segs;
  }
};

