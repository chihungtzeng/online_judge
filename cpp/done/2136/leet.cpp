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
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
  {
    using ipair = pair<int, int>;
    vector<ipair> pairs;
    for (int i = 0; i < plantTime.size(); i++)
    {
      pairs.push_back({ plantTime[i], growTime[i] });
    }
    auto comp = [](const auto& a, const auto& b) {
      if (a.second != b.second)
        return a.second > b.second;
      else
        return a.first < b.first;
    };
    sort(pairs.begin(), pairs.end(), comp);
    int gt = 0, pt = 0;
    for (auto& [p, g] : pairs)
    {
      pt += p;
      gt = max(gt - p, g);
    }
    return pt + gt;
  }
};
