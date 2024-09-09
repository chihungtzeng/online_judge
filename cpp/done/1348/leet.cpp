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

class TweetCounts {
 public:
  unordered_map<string, vector<int>> m;
  unordered_map<string, int> delta{
      {"minute", 60}, {"hour", 3600}, {"day", 3600 * 24}};
  TweetCounts() {}

  void recordTweet(string tweetName, int time) { m[tweetName].push_back(time); }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                         int startTime, int endTime) {
    vector<int> ans;
    auto tweet_it = m.find(tweetName);
    if (tweet_it == m.end()) return ans;
    auto tweet = tweet_it->second;
    int dt = delta[freq];
    ans.resize(1 + (endTime - startTime) / dt);

    for (auto v : tweet) {
      if (v >= startTime && v <= endTime) {
        int k = (v - startTime) / dt;
        ans[k]++;
      }
    }

    return ans;
  }
};
