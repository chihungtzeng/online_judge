#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
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

using ipair = pair<int, int>;
class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    vector<ipair> age_ranges(121);
    for (int i = 0; i <= 120; i++) {
      age_ranges[i] = find_range(i);
    }
    vector<int> npeople_of_age(121);
    for (auto age : ages) {
      npeople_of_age[age] += 1;
    }
    vector<int> psum(121);
    psum[0] = npeople_of_age[0];
    for (int i = 1; i <= 120; i++) {
      psum[i] = psum[i - 1] + npeople_of_age[i];
    }
#if 0    
    for(int i=0; i <= 120; i++){
      LOG(INFO) << "age " << i << " -> " << age_ranges[i];
    }
#endif
    int ans = 0;
    for (int age = 0; age <= 120; age++) {
      auto& [from, to] = age_ranges[age];
      if (from > to) continue;
      int amount = range_sum(psum, from, to) * npeople_of_age[age];
      if (age >= from && age <= to) {
        amount -= npeople_of_age[age];
      }
      ans += amount;
    }
    return ans;
  }
  int range_sum(vector<int>& psum, int from, int to) {
    if (from == 0)
      return psum[to];
    else
      return psum[to] - psum[from - 1];
  }
  ipair find_range(int age) { return {age / 2 + 8, age}; }
};
