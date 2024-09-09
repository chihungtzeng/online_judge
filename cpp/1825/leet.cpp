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

class MKAverage {
 private:
  multiset<int> small, large;
  deque<int> q;
  int m_, k_;
  int64_t total_, small_sum_, large_sum_;
  int divisor_;

 public:
  MKAverage(int m, int k)
      : m_(m), k_(k), total_(0), small_sum_(0), large_sum_(0) {
    divisor_ = m_ - 2 * k_;
  }

  void addElement(int num) {
    q.push_back(num);
    total_ += num;
    small_sum_ += num;
    large_sum_ += num;
    while (q.size() > m_) {
      int front = q.front();
      total_ -= front;

      auto it = small.find(front);
      if (it != small.end() && small.size() == k_) {
        small_sum_ -= front;
        small.erase(it);
      }

      it = large.find(front);
      if (it != large.end() && large.size() == k_) {
        large_sum_ -= front;
        large.erase(it);
      }

      q.pop_front();
    }
    small.insert(num);
    large.insert(num);
    while (small.size() > k_) {
      auto it = small.find(*small.crbegin());
      small_sum_ -= *it;
      small.erase(it);
    }
    while (large.size() > k_) {
      large_sum_ -= *large.begin();
      large.erase(large.begin());
    }
    //    LOG(INFO) << "total_: " << total_ << ", large_sum_: " << large_sum_ <<
    //    ", small_sum_: " << small_sum_;
  }

  int calculateMKAverage() {
    if (q.size() < m_)
      return -1;
    else
      return (total_ - large_sum_ - small_sum_) / divisor_;
  }
};
