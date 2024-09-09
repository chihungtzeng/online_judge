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
  int getWinner(vector<int>& arr, int k) {
    if (k >= arr.size() - 1) return *max_element(arr.begin(), arr.end());
    int winner = (arr[0] > arr[1]) ? 0 : 1;
    int num_win = 1;
    int challenger = 2;
    while (challenger < arr.size() && num_win < k) {
      if (arr[winner] > arr[challenger]) {
        num_win++;
        challenger++;
      } else {
        winner = challenger;
        challenger++;
        num_win = 1;
      }
      if (num_win == k) return arr[winner];
    }
    return arr[winner];
  }
};
