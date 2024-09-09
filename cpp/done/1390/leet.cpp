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

class Solution {
 public:
  vector<int> primes;
  int sumFourDivisors(vector<int>& nums) {
    int sum = 0;
    if (primes.empty()) {
      build_primes();
    }
    for (auto v : nums) {
      auto pfactors = pfactors_of(v);
      if (pfactors.size() > 3) continue;
      sum += helper(pfactors, v);
    }
    return sum;
  }
  int helper(vector<int>& pfactors, int v) {
    priority_queue<int, vector<int>, greater<int>> pq(pfactors.begin(),
                                                      pfactors.end());
    vector<int> factors(1, 1);
    while (!pq.empty()) {
      int cur = pq.top();
      while (!pq.empty() && pq.top() == cur) {
        pq.pop();
      }
      factors.push_back(cur);
      for (auto p : pfactors) {
        int64_t can = (int64_t)p * cur;
        if (v % can == 0) {
          pq.push(can);
        }
      }
    }
    if (factors.size() == 4) {
      return accumulate(factors.begin(), factors.end(), 0);
    }
    return 0;
  }
  vector<int> pfactors_of(int n) {
    vector<int> pfactors;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
      if (n % primes[i] == 0) {
        pfactors.push_back(primes[i]);
        pfactors.push_back(n / primes[i]);
      }
    }
    return pfactors;
  }
  void build_primes() {
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    int diff = 2;
    int cur = primes.back() + diff;
    while (cur <= 100000) {
      int is_prime = true;
      for (int i = 1;
           i < primes.size() && is_prime && primes[i] * primes[i] > cur; i++) {
        if (cur % primes[i] == 0) {
          is_prime = false;
        }
      }
      if (is_prime) {
        primes.push_back(cur);
      }
      diff = 6 - diff;
      cur += diff;
    }
  }
};
