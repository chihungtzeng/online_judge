#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
  private:
    map<int, std::vector<int>> m;
 public:
  Solution(vector<int>& nums) {
    m.clear();
    srand(time(nullptr));
    for(int i=0, bound=nums.size(); i<bound; i++)
    {
      auto val = nums[i];
      auto hit = m.find(val);
      if (hit == m.end())
      {
        m[val] = {i};
      }
      else {
        hit->second.push_back(i);
      }
    }
  }

  int pick(int target) {
    auto hit = m.find(target);
    if (hit->second.size() == 1)
    {
      return hit->second[0];
    }
    auto nelem = hit->second.size();
    auto idx = rand() % nelem;
    return hit->second[idx];

    }
};

