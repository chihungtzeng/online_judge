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
  int myAtoi(string s)
  {
    s = strip(s);
    s = extract(s);
    if (s.empty())
      return 0;

    int sign = 1;
    if (s[0] == '-')
      sign = -1;
    int i = 0;
    if (s[0] == '+' || s[0] == '-')
      i++;

    int64_t num = 0;
    while (i < s.size() && s[i] >= '0' && s[i] <= '9')
    {
      int d = s[i++] - '0';
      num = 10 * num + d * sign;
      if (num >= INT_MAX)
        return INT_MAX;
      if (num <= INT_MIN)
        return INT_MIN;
    }
    return num;
  }

  string strip(string& s)
  {
    int i = 0;
    while (i < s.size() && s[i] == ' ')
      i++;
    return s.substr(i);
  }

  string extract(string& s)
  {
    int i = 0;
    if (!s.empty() && (s[0] == '+' || s[0] == '-'))
      i++;

    while (i < s.size() && s[i] >= '0' && s[i] <= '9')
      i++;
    return s.substr(0, i);
  }
};
