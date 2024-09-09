#include "leet.cpp"

#include <gtest/gtest.h>

#include "glog/logging.h"
#include "glog/stl_logging.h"

TEST(kk, t1) {
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  Solution* solution = new Solution(head);

  // getRandom() should return either 1, 2, or 3 randomly. Each element should
  // have equal probability of returning.
  for(int i=0; i<10; i++){
    LOG(INFO) << solution->getRandom();
  }
  delete solution;
  delete head;
}

