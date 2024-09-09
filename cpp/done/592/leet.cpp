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

using ipair = pair<int, int>;

class Frac {
 public:
  int up_, down_;
  Frac(int up, int down) {
    int g = gcd(up, down);
    up_ = up / g;
    down_ = down / g;
  }
  Frac operator+(const Frac& other) {
    int g = gcd(down_, other.down_);
    int new_up = up_ * (other.down_ / g) + other.up_ * (down_ / g);
    int new_down = down_ * (other.down_ / g);
    return Frac{new_up, new_down};
  }
  string str() const { return to_string(up_) + '/' + to_string(down_); }
};

class Solution {
 public:
  string fractionAddition(string expression) {
    auto fracs = parse(expression);
    auto cur = fracs[0];
    for (int i = 1; i < fracs.size(); i++) {
      cur = cur + fracs[i];
    }
    return cur.str();
  }
  vector<Frac> parse(string& s) {
    int num = 0;
    ipair cur = {0, 0};
    vector<Frac> ret;
    int sign = 1;
    for (auto ch : s) {
      if (ch == '-') {
        sign = -1;
        if (num > 0) {
          cur.second = num;
          ret.push_back({cur.first, cur.second});
          cur = {0, 0};
          num = 0;
        }
      } else if (ch == '+') {
        sign = 1;
        cur.second = num;
        ret.push_back({cur.first, cur.second});
        cur = {0, 0};
        num = 0;
      } else if (ch == '/') {
        cur.first = sign * num;
        num = 0;
      } else {
        num = num * 10 + (ch - '0');
      }
    }
    if (num > 0) {
      cur.second = num;
      ret.push_back({cur.first, cur.second});
    }
    return ret;
  }
};
