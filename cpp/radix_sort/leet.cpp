#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

void radix_sort(std::vector<int>& nums)
{
  auto max_elem = *max_element(nums.begin(), nums.end());
  auto nelem = nums.size();
  int base = 1;
  std::vector<int> digits[10];
  for(int i=0; i<10; i++)
  {
    digits[i].reserve(nelem / 10);
  }
  while(base <= max_elem)
  {
    for(int i=0; i<10; i++)
    {
      digits[i].clear();
    }

    for(auto val: nums)
    {
      digits[(val / base) % 10].push_back(val);
    }
    int cur = 0;
    for(int i=0; i<10; i++)
    {
      for(auto val: digits[i])
      {
        nums[cur++] = val;
      }
    }
    base = base * 10;
  }
}
