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

struct Record {
  int est2t_, s2this_;
  string wheel_;

  Record(string wheel, int s2this, int est2t) : wheel_(std::move(wheel)) {
    est2t_ = est2t;
    s2this_ = s2this;
  }
  bool operator<(const Record& other) const {
    return est2t_ + s2this_ > other.est2t_ + other.s2this_;
  }
};

class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> nono{deadends.begin(), deadends.end()};
    string start = "0000";
    if (nono.find(start) != nono.end()) return -1;
    priority_queue<Record> pq;
    pq.push({start, 0, estimate(start, target)});
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if (cur.wheel_ == target) return cur.s2this_;

      auto cans = next(cur.wheel_);
      for (auto& can : cans) {
        if (nono.find(can) != nono.end()) continue;
        auto r = Record{can, 1 + cur.s2this_, estimate(can, target)};
        pq.push(r);
        nono.insert(can);
      }
    }
    return -1;
  }
  int estimate(string& s, string& t) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
      int dist = abs(s[i] - t[i]);
      ret += min(dist, 10 - dist);
    }
    return ret;
  }
  vector<string> next(string& s) {
    vector<string> ret;
    for (int i = 0; i < 4; i++) {
      auto tmp = s[i];
      s[i] = (s[i] - '0' + 1) % 10 + '0';
      ret.push_back(s);
      s[i] = (tmp - '0' + 9) % 10 + '0';
      ret.push_back(s);
      s[i] = tmp;
    }
    // LOG(INFO) << "s: " << s << " next: " << ret;
    return ret;
  }
};
