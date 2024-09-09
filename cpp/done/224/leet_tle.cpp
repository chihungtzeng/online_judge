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
  int calculate(string s) {
    return calculate2(s);
  }
  int64_t calculate2(string s) {
    s = remove_spaces(s);
    bool done = false;
    while (!done) {
      int pos = s.find('(');
      if (pos == string::npos) {
        s = parse_simple(s);
        done = true;
      } else {
        int balance = 1;
        int end = 0;
        for (int i = pos + 1; i < s.size() && balance != 0; i++) {
          if (s[i] == '(') balance++;
          if (s[i] == ')') balance--;
          if (balance == 0) end = i;
        }
        string t = s.substr(pos + 1, end - pos - 1);
        int64_t partial = calculate2(std::move(t));
        string s1 = s.substr(0, pos);
        if (!s1.empty()) {
          if (s1.back() == '-' && partial < 0) {
            s1.pop_back();
            s1.push_back('+');
            s1.append(to_string(-partial));
          } else if (s1.back() == '+' && partial < 0) {
            s1.pop_back();
            s1.append(to_string(partial));
          } else {
            s1.append(to_string(partial));
          }
        } else {
          s1 = to_string(partial);
        }

        s = s1 + s.substr(end + 1);
      }
    }
    return stoll(s);
  }
  string parse_simple(string& s) {
    int sign = 1;
    int64_t num = 0;
    int64_t val = 0;
    for (auto ch : s) {
      if (ch == '+') {
        val += sign * num;
        sign = 1;
        num = 0;
      } else if (ch == '-') {
        val += sign * num;
        sign = -1;
        num = 0;
      } else if (isdigit(ch)) {
        num = num * 10 + ch - '0';
      }
    }
    if (num != 0) {
      val += sign * num;
    }
    return to_string(val);
  }
  string remove_spaces(string& s) {
    string ret;
    for (auto ch : s) {
      if (ch != ' ') ret.push_back(ch);
    }
    return ret;
  }
};
