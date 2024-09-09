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
  string breakPalindrome(string p) {
    if (p.size() <= 1) return "";
    int i = 0, j = p.size() - 1;
    bool done = false;
    vector<int> cans;
    while (!done && i < j) {
      if (p[i] != 'a') {
        p[i] = 'a';
        done = true;
      } else {
        cans.push_back(j);
      }
      i++;
      j--;
    }
    // LOG(INFO) << "p: " << p << " cans:" << cans;
    if (done) return p;

    if (cans.empty()) return "";

    string ans = p;
    mutate(ans, cans.back());
    cans.pop_back();
    while (!cans.empty()) {
      string challenger = p;
      mutate(challenger, cans.back());
      cans.pop_back();
      if (challenger < ans) ans = challenger;
    }
    return ans;
  }

  void mutate(string& p, int pos) {
    if (p[pos] == 'a')
      p[pos] = 'b';
    else
      p[pos] = 'a';
  }
};
