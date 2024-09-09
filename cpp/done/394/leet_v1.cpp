#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <cassert>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    vector<size_t> stack;
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] == '[') {
        stack.push_back(i);
      } else if (s[i] == ']') {
        auto start = stack.back();
        auto end = i;
        auto pair = expand(s, start, end);
        auto seg = pair.first;
        auto move_ahead = pair.second;
        s = s.substr(0, start - move_ahead) + seg + s.substr(end + 1, s.size()-1);
        stack.pop_back();
        i = start - move_ahead + seg.size() - 1;
      }
    }
    assert(stack.empty());
    return s;
  }
  std::pair<string, size_t> expand(const string& s, int32_t start, int32_t end) {
    size_t move_ahead = 1;
    size_t pos = start - move_ahead;
    while (pos >= 0 && pos < s.size() && s[pos] <= '9' && s[pos] >= '0') {
      move_ahead += 1;
      pos = start - move_ahead;
    }
    move_ahead -= 1;
    pos = start - move_ahead;
    auto nrepeat = std::stoi(s.substr(pos, move_ahead));
    string repeat = s.substr(start + 1, end - start - 1);
    string seg = "";
    for (auto i = 0; i < nrepeat; i++) {
      seg += repeat;
    }
    return {seg, move_ahead};
  }
};
