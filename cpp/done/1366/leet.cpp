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
  string rankTeams(vector<string>& votes) {
    const int nrounds = votes[0].size();
    vector<vector<int>> cnt(26, vector<int>(nrounds + 1, -1));

    for (int i = 0; i < nrounds; i++) {
      cnt[votes[0][i] - 'A'][nrounds] = votes[0][i] - 'A';
    }
    for (auto& vote : votes) {
      for (int i = 0; i < nrounds; i++) {
        cnt[vote[i] - 'A'][i]--;
      }
    }
    sort(cnt.begin(), cnt.end());
    string ans;
    for (int i = 0; i < 26; i++) {
      if (cnt[i][nrounds] >= 0) {
        ans.push_back(cnt[i][nrounds] + 'A');
      }
    }
    return ans;
  }
};
