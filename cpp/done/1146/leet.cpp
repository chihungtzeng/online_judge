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

class SnapshotArray {
 public:
  unordered_map<int, map<int, int>> snaps_;
  int cur_snap_;
  SnapshotArray(int length) : cur_snap_(0) {}

  void set(int index, int val) { snaps_[index][cur_snap_] = val; }

  int snap() {
    cur_snap_++;
    return cur_snap_ - 1;
  }

  int get(int index, int snap_id) {
    /*
      for(auto& [key, val]: snaps_[index]){
        LOG(INFO) << key << " : " << val;
      }
      */
    auto it = snaps_[index].upper_bound(snap_id);
    if (it == snaps_[index].begin()) {
      return 0;
    } else {
      it--;
      return it->second;
    }
  }
};
