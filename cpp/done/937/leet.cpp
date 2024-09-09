#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
  vector<string> reorderLogFiles(vector<string>& logs)
  {
    vector<string> letter_logs, digit_logs;
    for (auto& s : logs)
    {
      if (is_digit_log(s))
        digit_logs.push_back(s);
      else
        letter_logs.push_back(s);
    }
    auto comp = [](const auto& s1, const auto& s2) {
      vector<string> ss{ s1, s2 }, prefix, suffix;
      for (int i = 0; i < 2; i++)
      {
        int j = ss[i].find_first_of(' ');
        suffix.push_back(ss[i].substr(j + 1));
        prefix.push_back(ss[i].substr(0, j));
      }
      if (suffix[0] != suffix[1])
        return suffix[0] < suffix[1];
      return prefix[0] < prefix[1];
    };

    sort(letter_logs.begin(), letter_logs.end(), comp);
    letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
    return letter_logs;
  }
  bool is_digit_log(const string& s)
  {
    return s.back() >= '0' && s.back() <= '9';
  }
};

