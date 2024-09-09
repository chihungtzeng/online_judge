#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
  int compress(vector<char>& chars)
  {
    int cnt = 0;
    int len = 0;
    char prev = 0;

    for (int i = 0; i < chars.size(); i++)
    {
      if (chars[i] == prev)
      {
        cnt++;
      }
      else
      {
        len = helper(chars, len, prev, cnt);
        prev = chars[i];
        cnt = 1;
      }
    }
    len = helper(chars, len, prev, cnt);
    chars.erase(chars.begin() + len, chars.end());
    return len;
  }
  int helper(vector<char>& chars, int len, char ch, int cnt)
  {
    if (!ch)
      return len;

    chars[len++] = ch;
    if (cnt > 1)
    {
      for (auto c : to_string(cnt))
      {
        chars[len++] = c;
      }
    }
    return len;
  }
};
