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
  string gcdOfStrings(string s1, string s2)
  {
    int g = gcd(s1.size(), s2.size());
    string ans = "";
    while (g)
    {
      if (s2.size() % g == 0 && s1.size() % g == 0 && s1.substr(0, g) == s2.substr(0, g) && repeat(s1, g) &&
          repeat(s2, g))
      {
        ans = s1.substr(0, g);
        break;
      }
      g--;
    }
    return ans;
  }
  bool repeat(string& s, int g)
  {
    int pos = g;
    string seg = s.substr(0, g);
    while (pos < s.size())
    {
      if (s.substr(pos, g) != seg)
      {
        return false;
      }
      pos += g;
    }
    return true;
  }
};
