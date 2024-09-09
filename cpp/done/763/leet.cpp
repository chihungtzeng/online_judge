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
  vector<int> partitionLabels(string s) {
    vector<int> start(26,-1), end(26,-1);
    for(int i=0; i<s.size(); i++){
      int idx = s[i] - 'a';
      if (start[idx] < 0) start[idx] = i;
      end[idx] = max(end[idx], i);
    }
    vector<vector<int>> intervals;
    for(int i=0; i<26; i++){
      if (start[i] >= 0){
        intervals.push_back({start[i], -1});
        intervals.push_back({end[i], 1});
      }
    }
    sort(intervals.begin(), intervals.end());
    vector<int> ans;
    int head=0, cnt=0, cur=0;
    while(cur <intervals.size()){
      cnt += intervals[cur][1];
      if (cnt == 0){
        ans.push_back(intervals[cur][0] - head + 1);
        if (cur < intervals.size() - 1)
          head = intervals[cur+1][0];
      }
      cur++;
    }
    return ans;
  }
};
