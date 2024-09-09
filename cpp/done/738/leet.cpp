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
  int monotoneIncreasingDigits(int n)
  {
    string s = to_string(n);
    for (int i = s.size() - 1; i >= 1; i--)
    {
      if (s[i] < s[i - 1])
      {
        s[i - 1]--;
        for (int j = i; j < s.size(); j++)
        {
          s[j] = '9';
        }
      }
    }
    return stoi(s);
  }
};

