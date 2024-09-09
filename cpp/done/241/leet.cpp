#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

enum op { plus, minus, multiply };

class Solution {
 public:
  std::map<std::pair<int, int>, vector<int>> cache;
  vector<int> diffWaysToCompute(string input) {
    auto tokens = split(input);
    return helper(tokens, 0, tokens.size() - 1);
  }

  std::vector<int> helper(std::vector<int> tokens, int left, int right) {
    if (left == right) {
      return std::vector<int>{tokens[left]};
    }
    map<std::pair<int, int>, vector<int>>::iterator it =
        cache.find(std::pair<int, int>{left, right});
    if (it != cache.end()) {
      return it->second;
    }
    vector<int> ret;
    ret.reserve(128);
    for (int i = left + 1; i < right; i += 2) {
      auto lret = helper(tokens, left, i - 1);
      auto rret = helper(tokens, i + 1, right);
      for (auto r1 : lret) {
        for (auto r2 : rret) {
          if (tokens[i] == op::plus) {
            ret.push_back(r1 + r2);
          } else if (tokens[i] == op::minus) {
            ret.push_back(r1 - r2);
          } else {
            ret.push_back(r1 * r2);
          }
        }
      }
    }
    cache[std::pair<int, int>{left, right}] = ret;
    return ret;
  }

  vector<int> split(string& input) {
    string cur;
    vector<int> toks;
    toks.reserve(input.size());

    for (auto ch : input) {
      switch (ch) {
        case '+':
          toks.push_back(std::stoi(cur));
          toks.push_back(op::plus);
          cur = "";
          break;
        case '-':
          if (cur.empty()) {
            cur = '-';
          } else {
            toks.push_back(std::stoi(cur));
            toks.push_back(op::minus);
            cur = "";
          }
          break;
        case '*':
          toks.push_back(std::stoi(cur));
          toks.push_back(op::multiply);
          cur = "";
          break;
        default:
          cur += ch;
          break;
      }
    }
    toks.push_back(std::stoi(cur));
    return toks;
  }
};
