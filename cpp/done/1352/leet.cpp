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

class ProductOfNumbers {
 public:
  vector<int64_t> ps;
  ProductOfNumbers() { ps = {1}; }

  void add(int num) {
    if (num == 0)
      ps = {1};
    else
      ps.push_back(ps.back() * num);
  }

  int getProduct(int k) {
    if (ps.size() <= k) {
      return 0;
    } else {
      return ps.back() / ps[ps.size() - k - 1];
    }
  }
};
