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

class Solution {
 public:
  vector<int> distributeCandies(int candies, int num_people) {
    int64_t m8 = 8ul * candies;
    int64_t rounds = (-1 + sqrt(1 + m8)) / 2;
    if (rounds * (rounds + 1) / 2 < candies) {
      rounds++;
    }
    int64_t last = candies - rounds * (rounds - 1) / 2;
    vector<int> ans(num_people);
    for (int i = 1; i <= rounds; i++) {
      ans[(i - 1) % num_people] += i;
    }

    ans[(rounds - 1) % num_people] -= rounds;
    ans[(rounds - 1) % num_people] += last;

    return ans;
  }
};
