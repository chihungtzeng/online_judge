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
    unordered_map<int, int> combs;
    for (auto& q : queries) {
      ans.push_back(calc(q[0], q[1], combs, primes));
    }
    return ans;
  }
  vector<int> calc_pfs(int n, vector<int>& primes) {
    vector<int> pfs;
    for (int i = 0; primes[i] * primes[i] <= n; i++) {
      int p = 0;
      while (n % primes[i] == 0) {
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
    if (pfs.empty()) {
      pfs.push_back(1);
    }
    return pfs;
  }
  vector<int> calc_primes() {
    vector<int> primes{2, 3, 5};
    int offset = 2;
    int cur = 5;
    while (cur <= 100) {
      cur += offset;
      offset = 6 - offset;
      bool is_prime = true;
      for (int i = 0;
           i < primes.size() && primes[i] * primes[i] <= cur && is_prime; i++) {
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

  int calc(const int ndigit, const int prod, unordered_map<int, int>& combs,
           vector<int>& primes) {
    if (ndigit == 1 || prod == 1) {
      return 1;
    }
    auto pfs = calc_pfs(prod, primes);
    uint64_t res = 1;
    for (auto p : pfs) {
      // calc choose(ndigit+p-1, p);
      int n = ndigit + p - 1;
      res = (res * calc_comb(n, p, combs)) % base;
    }
    return res;
  }
  int calc_comb(int n, int p, unordered_map<int, int>& combs) {
    if (n == p || p == 0) return 1;
    if (n == p + 1 || p == 1) return n;
    if (n < p) {
      return 0;
    }
    int key = (n << 16) + p;
    auto it = combs.find(key);
    if (it != combs.end()) {
      return it->second;
    }
    int res =
        (calc_comb(n - 1, p, combs) + calc_comb(n - 1, p - 1, combs)) % base;
    combs[key] = res;
    return res;
  }
};
