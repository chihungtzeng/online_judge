#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <cassert>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    if (s.empty())
      return s;
    int dstart = -1;
    for (int i = 0; i < s.size(); i++)
    {
      if (isdigit(s[i]))
      {
        dstart = i;
        break;
      }
    }
    if (dstart < 0)
      return s;
    int dend = dstart;
    for (int i = dstart; i < s.size(); i++)
    {
      if (!isdigit(s[i]))
      {
        break;
      }
      dend = i;
    }
    int bstart = dend + 1, bend = 0;
    int balance = 0;
    for (int i = bstart; i < s.size(); i++)
    {
      if (s[i] == '[')
        balance++;
      else if (s[i] == ']')
        balance--;

      if (balance == 0)
      {
        bend = i;
        break;
      }
    }

    string res;
    if (dstart > 0)
      res = s.substr(0, dstart);
    int nrepeat = stoi(s.substr(dstart, dend - dstart + 1));
    string inner = decodeString(s.substr(bstart + 1, bend - bstart - 1));
    while (nrepeat--)
    {
      res += inner;
    }
    res += decodeString(s.substr(bend + 1));
    return res;
  }
};
