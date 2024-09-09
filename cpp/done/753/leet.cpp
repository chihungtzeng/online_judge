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

class Solution {
 public:
  string crackSafe(int n, int k) {
    unordered_set<string> vis;
    string stub = string(n, '0');
    vis.insert(stub);
    int bound = 1;
    for (int i = 0; i < n; i++) {
      bound *= k;
    }
    helper(n, k, stub, bound, vis);
    return stub;
  }
  int helper(int n, int k, string& stub, const int bound,
             unordered_set<string>& vis) {
    if (vis.size() == bound) return 0;
    string suffix = stub.substr(stub.size() - (n - 1));
    for (int i = 0; i < k; i++) {
      suffix.push_back('0' + i);
      if (vis.find(suffix) == vis.end()) {
        stub.push_back('0' + i);
        vis.insert(suffix);
        int ret = helper(n, k, stub, bound, vis);
        if (ret == 0) {
          return 0;
        } else {
          vis.erase(suffix);
          stub.pop_back();
        }
      }
      suffix.pop_back();
    }
    return 1;
  }
};
