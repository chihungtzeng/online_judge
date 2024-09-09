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

constexpr int base = 1e9 + 7;
class Solution {
 public:
  vector<int> waysToFillArray(vector<vector<int>>& queries) {
    vector<int> ans;
    auto primes = calc_primes();
    for(auto& query: queries) {
      auto pfs = calc_pfs(query[1], primes);
      LOG(INFO) << query[1] << ": " << pfs;
    }


#if 0
    unordered_map<int, int> cache;
    for (auto& q : queries) {
      ans.push_back(calc(q[0], q[1], cache));
    }
#endif    
    return ans;
  }
  vector<int> calc_pfs(int n, vector<int>& primes)
  {
    vector<int> pfs;
    for(int i=0; primes[i]*primes[i] <=n; i++){
      int p = 0;
      while (n % primes[i] == 0){
        p++;
        n = n / primes[i];
      }
      if (p > 0) {
        pfs.push_back(p);
      }
    }
    if (n > 1) {
      pfs.push_back(1);
    }
    return pfs;
  }
  vector<int> calc_primes()
  {
    vector<int> primes{2,3, 5};
    int offset = 2;
    int cur = 5;
    while (cur <= 10000) {
      cur += offset;
      offset = 6 -offset;
      bool is_prime = true;
      for(int i=0; i<primes.size() && primes[i]*primes[i] <= cur && is_prime; i++){
        if (cur % primes[i] == 0) {
          is_prime = false;
        }
      }
      if (is_prime) {
        primes.push_back(cur);
      }
    }
    return primes;
  }

  int calc(const int ndigit, const int prod, unordered_map<int, int>& cache) {
    if (ndigit == 1 || prod == 1) {
      return 1;
    }
    int key = (ndigit << 16) + prod;
    auto it = cache.find(key);
    if (it != cache.end()) {
      return it->second;
    }
    int res = 0;
    int sq = sqrt(prod);
    for (int i = 1; i <= sq; i++) {
      if (prod % i == 0) {
        int q = prod / i;
        res += calc(ndigit - 1, q, cache);
        res %= base;
        if (q != i) {
          res += calc(ndigit - 1, i, cache);
          res %= base;
        }
      }
    }
    cache[key] = res;
    return res;
  }
};
