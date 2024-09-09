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
  long long smallestNumber(long long num)
  {
    bool neg = false;
    if (num < 0)
    {
      neg = true;
      num = abs(num);
    }
    int nz = 0;
    vector<char> digits;
    for (auto ch : to_string(num))
    {
      if (ch == '0')
        nz++;
      else
        digits.push_back(ch);
    }
    sort(digits.begin(), digits.end());
    if (neg)
    {
      reverse(digits.begin(), digits.end());
    }
    string ans;
    if (!digits.empty())
    {
      ans.push_back(digits[0]);
    }
    while (nz && !neg)
    {
      ans.push_back('0');
      nz--;
    }
    for (int i = 1; i < digits.size(); i++)
    {
      ans.push_back(digits[i]);
    }
    while (nz && neg)
    {
      ans.push_back('0');
      nz--;
    }
    long long res = stol(ans);
    if (neg)
      res = -res;
    return res;
  }
};
