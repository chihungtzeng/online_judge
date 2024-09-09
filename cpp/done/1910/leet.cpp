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
  string removeOccurrences(string s, string part)
  {
    string temp;
    int pt = part.size();
    for (int i = 0; i < s.size(); i++)
    {
      temp.push_back(s[i]);
      if (temp.size() < pt)
        continue;
      int nt = temp.size();
      if (temp.substr(nt - pt, pt) == part)
      {
        temp = temp.substr(0, nt - pt);
      }
    }
    return temp;
  }
};
