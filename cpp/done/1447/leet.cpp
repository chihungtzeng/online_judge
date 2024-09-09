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
  vector<string> simplifiedFractions(int n) {
    vector<string> ret;
    for (int i = 2; i <= n; i++) {
      ret.emplace_back("1/" + to_string(i));
      for (int j = 2; j < i; j++) {
        if (gcd(i, j) == 1) {
          ret.emplace_back(to_string(j) + "/" + to_string(i));
        }
      }
    }
    return ret;
  }
};
