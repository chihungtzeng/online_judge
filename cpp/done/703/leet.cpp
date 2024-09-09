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

struct cmp {
  bool operator()(const int &a, const int &b) const { return a > b; }
};

class KthLargest {
 public:
  int k_;
  priority_queue<int, vector<int>, cmp> pq_;
  KthLargest(int k, vector<int> &nums) : k_(k), pq_(nums.begin(), nums.end()) {}

  int add(int val) {
    pq_.push(val);
    while (pq_.size() > k_) {
      pq_.pop();
    }
    return pq_.top();
  }
};

