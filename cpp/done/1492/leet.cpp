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
  vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  int kthFactor(int n, int k) {
    for(int i=primes.back() + 2; i<=1000; i+=2){
      bool is_prime = true;
      for(auto p: primes) {
        if (p*p > i) break;
        if (i % p == 0) {
          is_prime = false;
          break;
        }
      }
      if (is_prime){
        primes.push_back(i);
      }
    }

    vector<int> pfactors;
    for (auto p : primes) {
      if (n % p == 0) pfactors.push_back(p);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(n);
    while (!pq.empty() && k--) {
      int ret = pq.top();
      if (k == 0) return ret;
      pq.pop();
      while (!pq.empty() && pq.top() == ret) {
        pq.pop();
      }
      for (auto p : pfactors) {
        int v = p * ret;
        if (n % v == 0) {
          pq.push(v);
        }
      }
    }
    return -1;
  }
};
