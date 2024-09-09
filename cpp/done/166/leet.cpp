#include <algorithm>
#include <cstdint>
#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  string fractionToDecimal(int a, int b)
  {
    if (a == 0)
      return "0";

    int sign = 1;
    if ((a < 0 && b > 0) || (a > 0 && b < 0))
      sign = -1;
    int64_t A = a, B = b;
    A = abs(A);
    B = abs(B);
    if (B == 1)
      return to_string(sign * A);
    int64_t d = A / B, r = A % B;
    if (r == 0) {
      return to_string(sign * d);
    }
    unordered_map<uint64_t, int> memo;
    vector<char> decimals;
    bool done = false;
    string suffix;
    while (!done)
    {
      char c = (r * 10) / B + '0';
      auto it = memo.find(r);
      if (it == memo.end())
      {
        memo[r] = decimals.size();
        decimals.push_back(c);
      }
      r = (r * 10) % B;

      if (r == 0)
      {
        done = true;
        for (auto ch : decimals)
        {
          suffix.push_back(ch);
        }
      }
      else
      {
        auto it = memo.find(r);
        if (it != memo.end())
        {
          done = true;
          int pos = it->second;
          for (int i = 0; i < pos; i++)
          {
            suffix.push_back(decimals[i]);
          }
          suffix.push_back('(');
          for (int i = pos; i < decimals.size(); i++)
          {
            suffix.push_back(decimals[i]);
          }
          suffix.push_back(')');
        }
      }
    }
    string ans;
    if (sign < 0)
      ans.push_back('-');
    return ans + to_string(d) + "." + suffix;
  }
};
