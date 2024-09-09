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

using ipair = pair<int, int>;
class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    const int n = ages.size();
    vector<ipair> age_scores;
    for (int i = 0; i < n; i++) {
      age_scores.push_back({ages[i], scores[i]});
    }
    sort(age_scores.begin(), age_scores.end(), greater<>());

    vector<int> dp(n);
    dp[0] = age_scores[0].second;
    int ans = dp[0];
    for (int i = 1; i < n; i++) {
      dp[i] = age_scores[i].second;
      for (int j = 0; j < i; j++) {
        bool conflict = bool(age_scores[i].second > age_scores[j].second &&
                             age_scores[i].first < age_scores[j].first);
        if (!conflict) {
          dp[i] = max(dp[i], dp[j] + age_scores[i].second);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
