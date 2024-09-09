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

class AuthenticationManager {
 public:
  unordered_map<string, uint64_t> tokens;
  multiset<uint64_t> expire_ts;
  int ttl;

  AuthenticationManager(int timeToLive) : ttl(timeToLive) {}

  void generate(string tokenId, int currentTime) {
    uint64_t ts = currentTime + ttl;
    tokens[tokenId] = ts;
    expire_ts.insert(ts);
  }

  void renew(string tokenId, int currentTime) {
    auto it = tokens.find(tokenId);
    if (it == tokens.end()) {
      return;
    }
    if (it->second > currentTime) {
      auto it2 = expire_ts.find(it->second);
      expire_ts.erase(it2);
      uint64_t ts = currentTime + ttl;
      tokens[tokenId] = ts;
      expire_ts.insert(ts);
    }
  }

  int countUnexpiredTokens(int currentTime) {
    while (!expire_ts.empty() && (*expire_ts.begin() <= currentTime)) {
      expire_ts.erase(expire_ts.begin());
    }
    return expire_ts.size();
  }
};

