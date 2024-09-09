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

class Cashier {
 public:
  unordered_map<int, int> i2p_;
  double drate_;
  int n_;
  int kth_;
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
    n_ = n;
    kth_ = 0;
    drate_ = 1.0 - discount / 100.0;
    for (int i = 0; i < products.size(); i++) {
      i2p_[products[i]] = prices[i];
    }
  }

  double getBill(vector<int> product, vector<int> amount) {
    kth_++;
    int total = 0;
    for (int i = product.size() - 1; i >= 0; i--) {
      total += i2p_[product[i]] * amount[i];
    }
    if (kth_ % n_ == 0) {
      return total * drate_;
    }
    return total;
  }
};
