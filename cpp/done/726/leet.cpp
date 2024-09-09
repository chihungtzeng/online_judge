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

using i4 = tuple<int, int, int, int>;
class Solution {
 public:
  string countOfAtoms(string formula) {
    auto atoms = parse(formula);
    string ans;
    for (auto& [key, val] : atoms) {
      if (val > 1) {
        ans += key + to_string(val);
      } else {
        ans += key;
      }
    }
    return ans;
  }
  map<string, int> parse(string& s) {
    map<string, int> ans;
    bool done = false;
    while (!done) {
      auto [start, end, dstart, dend] = next_block(s);
      if (start < 0) {
        done = true;
        break;
      }
      string t = s.substr(start + 1, end - start - 1);
      auto atoms = parse(t);
      int scale = 1;
      if (dstart > end) {
        scale = stoi(s.substr(dstart, dend - dstart + 1));
      }
      for (auto& [key, val] : atoms) {
        ans[key] += val * scale;
      }
      s = s.substr(0, start) + s.substr(dend + 1);
    }
    auto atoms = parse_simple(s);
    for (auto& [key, val] : atoms) {
      ans[key] += val;
    }
    return ans;
  }
  map<string, int> parse_simple(string& s) {
    map<string, int> ans;
    string atom;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      if (isupper(s[i])) {
        if (!atom.empty()) {
          ans[atom] += max(1, cnt);
        }
        atom = s[i];
        cnt = 0;
      } else if (islower(s[i])) {
        atom.push_back(s[i]);
      } else if (isdigit(s[i])) {
        cnt = cnt * 10 + s[i] - '0';
      }
    }
    if (!atom.empty()) {
      ans[atom] += max(1, cnt);
    }
    return ans;
  }
  i4 next_block(string& s) {
    int start = s.find('(');
    if (start == string::npos) return {-1, -1, -1, -1};
    int balance = 1;
    int end = start + 1;
    while (end < s.size()) {
      if (s[end] == '(')
        balance++;
      else if (s[end] == ')') {
        balance--;
        if (balance == 0) {
          break;
        }
      }
      end++;
    }
    int dstart = end + 1, dend = end + 1;
    if (dend < s.size() && isdigit(s[dend])) {
      while (dend < s.size() && isdigit(s[dend])) dend++;
      dend--;
    } else {
      dstart = end;
      dend = end;
    }
    return {start, end, dstart, dend};
  }
};
