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

constexpr int base = 1e9 + 7;
using ituple = tuple<int, int, int>;  // kth_op, op, op_arg
class Fancy {
 public:
  vector<int> vals;
  int kth_op;
  vector<int> append_time;
  vector<ituple> ops;

  Fancy() { kth_op = 0; }

  void append(int val) {
    vals.push_back(val);
    append_time.push_back(kth_op);
    kth_op++;
  }

  void addAll(int inc) {
    ops.push_back({kth_op, 1, inc});
    kth_op++;
  }

  void multAll(int m) {
    ops.push_back({kth_op, 2, m});
    kth_op++;
  }

  int use_op_since(int k) {
    int left = 0, right = ops.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      auto [kth_op, op, arg] = ops[mid];
      if (kth_op < k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }

  int getIndex(int idx) {
    if (idx >= vals.size()) return -1;
    int k = append_time[idx];
    int val = vals[idx];

    int kth_op = use_op_since(k);
    int64_t ans = val;
    while (kth_op < ops.size()) {
      auto [_, op, arg] = ops[kth_op];
      if (op == 1) {
        ans = (ans + arg) % base;
      } else if (op == 2) {
        ans = (ans * arg) % base;
      }
      kth_op++;
    }
    return ans;
  }
};

