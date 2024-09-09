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
  unordered_map<string, multiset<int>> m;
  unordered_map<string, int> delta{
      {"minute", 60}, {"hour", 3600}, {"day", 3600 * 24}};
  TweetCounts() {}

  void recordTweet(string tweetName, int time) { m[tweetName].insert(time); }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                         int startTime, int endTime) {
    vector<int> ans;
    auto tweet_it = m.find(tweetName);
    if (tweet_it == m.end()) return ans;
    auto tweet = tweet_it->second;
    int dt = delta[freq];
    ans.resize(1 + (endTime - startTime) / dt);

    auto it = lower_bound(tweet.begin(), tweet.end(), startTime);
    while (it != tweet.end() && *it <= endTime) {
      int k = (*it - startTime) / dt;
      ans[k]++;
      it++;
    }

    return ans;
  }
};
