#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValidSerialization(string preorder) {
    auto fields = split(preorder);
    auto t = reduce(fields);
    return bool(t.size() == 1 && t[0] == "#");
  }
  std::vector<string> reduce(std::vector<string>& fields) {
    std::vector<string> cur = fields, next;
    bool done = false;
    while (!done) {
      next.clear();
      size_t idx = 0;
      done = true;
      while (idx < cur.size()) {
        if (cur.size() >= 3 && idx <= cur.size() - 3 && cur[idx] != "#" &&
            cur[idx + 1] == "#" && cur[idx + 2] == "#") {
          next.emplace_back("#");
          idx += 3;
          done = false;
        } else {
          next.push_back(cur[idx]);
          idx += 1;
        }
      }
      cur = next;
    }
    return cur;
  }
  std::vector<string> split(string& preorder) {
    std::vector<string> ret;
    ret.reserve(preorder.size());
    string tok;
    for (auto ch : preorder) {
      if (ch == ',') {
        ret.emplace_back(tok);
        tok = "";
      } else {
        tok += ch;
      }
    }
    if (!tok.empty()) {
      ret.emplace_back(tok);
    }
    return ret;
  }
};
