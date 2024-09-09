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

using ipair = pair<int, int>;
class Solution
{
public:
  string solveEquation(string eq)
  {
    istringstream iss(eq);
    string token;
    vector<ipair> sides;
    while (getline(iss, token, '='))
    {
      sides.push_back(parse_token(token));
    }
    // LOG(INFO) << "lhs: " << sides[0] << ", rhs: " << sides[1];
    sides[0].first -= sides[1].first;
    sides[1].second -= sides[0].second;
    if (sides[0].first == 0)
    {
      if (sides[1].second != 0)
      {
        return "No solution";
      }
      else
      {
        return "Infinite solutions";
      }
    }
    else
    {
      int x = sides[1].second / sides[0].first;
      return "x=" + to_string(x);
    }
  }
  ipair parse_token(string& s)
  {
    string token;
    int sign = 1;
    int a = 0, b = 0;
    for (auto ch : s)
    {
      if (isdigit(ch))
      {
        token.push_back(ch);
      }
      else if (ch == 'x')
      {
        if (token.empty())
        {
          a += sign;
        }
        else
        {
          a += sign * stoi(token);
        }
        sign = 1;
        token = "";
      }
      else if (ch == '+')
      {
        if (!token.empty())
        {
          b += sign * stoi(token);
        }
        sign = 1;
        token = "";
      }
      else if (ch == '-')
      {
        if (!token.empty())
        {
          b += sign * stoi(token);
        }
        sign = -1;
        token = "";
      }
    }
    if (!token.empty())
    {
      b += sign * stoi(token);
    }
    return ipair{ a, b };
  }
};
