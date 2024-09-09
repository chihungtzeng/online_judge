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

constexpr char chs[62 + 1] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
class Solution {
 public:
  vector<string> stol_;
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    int64_t n = stol_.size();
    stol_.push_back(longUrl);
    return to_base62(n);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    int64_t pos = from_base62(shortUrl);
    return stol_[pos];
  }

  string to_base62(int64_t n) {
    string ret;
    if (n == 0) return "a";
    while (n > 0) {
      ret.push_back(chs[n % 62]);
      n = n / 62;
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }

  int64_t from_base62(string& s) {
    if (s == "a") return 0;
    int64_t ret = 0;
    for (auto ch : s) {
      if ('a' <= ch && ch <= 'z') {
        ret = ret * 62 + ch - 'a';
      } else if ('A' <= ch && ch <= 'Z') {
        ret = ret * 62 + ch - 'A' + 26;
      } else {
        ret = ret * 62 + ch - '0' + 52;
      }
    }
    return ret;
  }
};
