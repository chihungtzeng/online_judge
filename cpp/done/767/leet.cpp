#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
  string reorganizeString(string s)
  {
    vector<int> cnt(26);
    for (auto ch : s)
    {
      cnt[ch - 'a']++;
    }
    int idx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    int n = s.size();
    if (n % 2 == 0 && cnt[idx] > n / 2)
      return "";
    if (n % 2 == 1 && cnt[idx] > n / 2 + 1)
      return "";

    int i = 0;
    for (; i < n && cnt[idx] > 0; i += 2)
    {
      s[i] = idx + 'a';
      cnt[idx]--;
    }
    for (int j = 0; j < 26; j++)
    {
      while (cnt[j] > 0)
      {
        if (i >= n)
        {
          i = 1;
        }
        s[i] = j + 'a';
        cnt[j]--;
        i += 2;
      }
    }
    return s;
  }
};
