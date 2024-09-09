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

struct Complex {
  int a_, b_;
  Complex(int a, int b) : a_(a), b_(b) {}
  Complex operator*(const Complex& other) {
    int a1 = (a_ * other.a_) - (b_ * other.b_);
    int b1 = (a_ * other.b_) + (b_ * other.a_);
    return Complex{a1, b1};
  }
  string to_string() const {
    return std::to_string(a_) + '+' + std::to_string(b_) + 'i';
  }
};

class Solution {
 public:
  Complex parse_complex(string& s) {
    string real, imagine;
    auto plus_pos = s.find('+');
    real = s.substr(0, plus_pos);
    imagine = s.substr(plus_pos + 1);
    return Complex{stoi(real), stoi(imagine)};
  }
  string complexNumberMultiply(string a, string b) {
    auto c1 = parse_complex(a);
    auto c2 = parse_complex(b);
    auto c = c1 * c2;
    return c.to_string();
  }
};
