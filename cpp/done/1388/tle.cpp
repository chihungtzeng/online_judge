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
  int maxSizeSlices(vector<int>& slices) {
    map<vector<int>, int> cache;

  return helper(slices, cache);}

  int helper(vector<int> slices, map<vector<int>, int>& cache){
    if (slices.empty()) return 0;
    auto it = cache.find(slices);
    if (it != cache.end()){
      return it->second;
    }

    int best = -1;
    int best_i = -1;
    for(int i=slices.size()-1; i>=0; i--){
      int alice = (i + 1) % slices.size();
      int bob = (i-1 + slices.size()) % slices.size();
      vector<int> removed;
      for(int j=0; j<slices.size();j++){
        if (j != alice && j != bob && j != i){
          removed.push_back(slices[j]);
        }
      }
      if (helper(removed, cache) + slices[i] > best){
        best = helper(removed, cache) + slices[i];
        best_i = i;
      }
    }
    // LOG(INFO) << "slices: " << slices << " best pick: " << best_i << " best: " << best;
    cache[slices] = best;
    return best;
  }
};
