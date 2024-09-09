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
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
  {
    unordered_map<string, int> ell2;
    for (int i = list2.size() - 1; i >= 0; i--)
    {
      ell2[list2[i]] = i;
    }
    int least = INT_MAX;
    vector<string> ans;
    for (int i = 0; i < list1.size(); i++)
    {
      auto it = ell2.find(list1[i]);
      if (it == ell2.end())
        continue;
      if (i + it->second < least)
      {
        ans.clear();
        ans.push_back(list1[i]);
        least = i + it->second;
      }
      else if (i + it->second == least)
      {
        ans.push_back(list1[i]);
      }
    }
    return ans;
  }
};
