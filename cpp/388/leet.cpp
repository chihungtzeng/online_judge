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

struct FNode {
  string name_;
  vector<FNode *> kids_;
  bool is_file_;
  int path_len_;

  FNode(string& name): name_(name) {
  }
};

class Solution {
 public:
  int lengthLongestPath(string input) {
    LOG(INFO) << input;
  return 0;}
};
