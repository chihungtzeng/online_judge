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
  int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    int nelem = 1 << (N-1);
    if (K > nelem / 2) {
      return 1 - kthGrammar(N-1, K - nelem / 2);
    } else {
      return kthGrammar(N-1, K);
    }
  }
};
