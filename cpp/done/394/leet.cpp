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

using ituple = tuple<int, int, int>;
class Solution
{
public:
  string decodeString(string s)
  {
    string res;
    for (int i = 0; i < s.size(); i++)
    {
      if (!isdigit(s[i]))
      {
        res += s[i];
      }
      else
      {
        auto [rep, bstart, bend] = parse(s, i);
        auto ret = decodeString(s.substr(bstart + 1, bend - bstart - 1));
        while (rep--)
          res += ret;
        i = bend;
      }
    }
    return res;
  }
  ituple parse(const string& s, int start)
  {
    int b = 0;
    int rep = 0;
    int cur = start;
    while (isdigit(s[cur]))
    {
      rep = rep * 10 + s[cur] - '0';
      cur++;
    }
    int bstart = cur;
    b = 1;
    cur++;
    while (b != 0 && cur < s.size())
    {
      if (s[cur] == '[')
        b++;
      else if (s[cur] == ']')
        b--;

      cur++;
    }
    return { rep, bstart, cur - 1 };
  }
};
