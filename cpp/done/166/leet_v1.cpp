#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

struct Frac {
  bool neg;
  int gt0;
  string no_recur;
  string recur;
};

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (denominator == 1) {
      return std::to_string(numerator);
    }
    if (denominator == -1){
      return std::to_string(-static_cast<long long>(numerator));
    }

    auto frac = calc_frac(static_cast<long long>(numerator), static_cast<long long>(denominator));
    string ret;
    if (frac.neg) {
      ret.append(1, '-');
    }
    ret.append(std::to_string(frac.gt0));
    if (frac.no_recur.length() > 0 || frac.recur.length() > 0) {
      ret.append(1, '.');
    }

    if (frac.no_recur.length() > 0) {
      ret.append(frac.no_recur);
    }
    if (frac.recur.length() > 0) {
      ret.append(1, '(');
      ret.append(frac.recur);
      ret.append(1, ')');
    }

    return ret;
  }

  struct Frac calc_frac(long long up, long long down) {
    struct Frac ret;
    ret.neg = bool(((up < 0) && (down >0)) || (up > 0 && down < 0));
    up = std::abs(up);
    down = std::abs(down);
    auto temp = std::gcd(up, down);
    up /= temp;
    down /= temp;
    ret.gt0 = up / down;
    up = up % down;
    std::vector<long long> q;
    std::unordered_map<long long, int> index_map;
    int idx = 0;
    int recur_at = 0;
    while (up > 0) {
      up = (up << 3u) + (up << 1u);
      if (index_map.find(up) != index_map.end()) {
        recur_at = index_map[up];
        break;
      }
      q.push_back(up / down);
      index_map[up] = idx;
      idx++;
      up = up % down;
    }
    if (up != 0){
      for (int i = 0; i < recur_at; i++) {
        ret.no_recur.append(1, '0' + q[i]);
      }
      for (int i = recur_at; i < q.size(); i++) {
        ret.recur.append(1, '0' + q[i]);
      }
    } else {
      for(int i=0; i<q.size(); i++)
      {
        ret.no_recur.append(1, '0' + q[i]);
      }
    }
    return ret;
  }
};
