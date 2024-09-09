#include <glog/logging.h>
#include <glog/stl_logging.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  ~ListNode() {
    if(next) {
      delete next;
      next = nullptr;
    }
  }
};

class Solution {
 public:
  ListNode *head_;
  int nnode_;
  /** @param head The linked list's head.
          Note that the head is guaranteed to be not null, so it contains at
     least one node. */
  Solution(ListNode *head) : head_(head) {
    nnode_ = 0;
    auto *cur = head;
    while (cur) {
      nnode_++;
      cur = cur->next;
    }
    srand(time(NULL));
  }

  /** Returns a random node's value. */
  int getRandom() {
    if (nnode_ == 0) {
      return 0;
    }
    size_t pos = rand() % nnode_;
    auto *cur = head_;
    while (pos--) {
      cur = cur->next;
    }
    return cur->val;
  }
};

