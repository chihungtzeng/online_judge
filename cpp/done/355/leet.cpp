#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Post {
  int id_;
  int seq_;
  bool operator<(const Post& rhs) const{
    return bool(seq_ < rhs.seq_);
  }
  Post(int id, int seq): id_(id), seq_(seq) {}
};

using post_t = std::priority_queue<Post>;
//, vector<Post>, Post>;

class Twitter {
 public:
  unordered_map<int, post_t> id_posts_;
  unordered_map<int, set<int>> id_follows_;
  int post_seq_;
  /** Initialize your data structure here. */
  Twitter(): post_seq_(0) {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    id_posts_[userId].push({tweetId, post_seq_});
    post_seq_++;
    }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    auto tids = getPosts(userId);
    priority_queue<Post> pq(tids.begin(), tids.end());
    if (id_follows_.count(userId)) {
      for (auto& fid : id_follows_[userId]) {
        for (auto tid : getPosts(fid)) {
          pq.push(tid);
        }
      }
    }
    vector<int> ret;
    for (int i = 0; i < 10 && !pq.empty(); i++) {
      ret.push_back(pq.top().id_);
      pq.pop();
    }
    return ret;
  }

  vector<Post> getPosts(int uid) {
    auto& posts = id_posts_[uid];
    vector<Post> ret;
    ret.reserve(10);
    for (int i = 0; i < 10 && !posts.empty(); i++) {
      ret.push_back(posts.top());
      posts.pop();
    }
    for (size_t i = 0; i < ret.size(); i++) {
      posts.push(ret[i]);
    }
    return ret;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      id_follows_[followerId].insert(followeeId);
    }
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    if (id_follows_.count(followerId) == 0) {
      return;
    }
    if (id_follows_[followerId].count(followeeId) == 0) {
      return;
    }
    id_follows_[followerId].erase(followeeId);
  }
};

