#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

using Callback = function<int(const void *)>;

class Job
{
public:
  int64_t exec_time_;
  Callback cb_;
  const void* param_;

  Job(int64_t exec_time, Callback cb, const void* param) : exec_time_(exec_time), cb_(cb), param_(param)
  {
  }

  int64_t timeout_in_millis() {
    return exec_time_;
  }

  int fire() {
    return cb_(param_);
  }

  bool operator<(const Job& other) const {
    return exec_time_ < other.exec_time_;
  }
  bool operator>(const Job& other) const {
    return exec_time_ > other.exec_time_;
  }

};
