#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"


vector<int> list2vec(ListNode* head) {
  vector<int> nums;
  while (head) {
    nums.push_back(head->val);
    head = head->next;
  }
  return nums;
}

ListNode* vec2list(vector<int>& vec) {
  ListNode* head = nullptr;
  ListNode* prev = nullptr;
  for(auto val: vec) {
    ListNode* cur = new ListNode(val);
    if (!head) {
      head = cur;
    }
    if (prev) {
      prev->next = cur;
    }
    prev = cur;
  }
  return head;
}

TEST(kk, t0) {
  vector<int> nums{1, 2, 3};

  ListNode *head = vec2list(nums);
  auto ret = list2vec(head);
  EXPECT_EQ(nums, ret);

  delete head;
//  EXPECT_EQ(sol.trailingZeroes(3), 0);
}

TEST(kk, t1) {
  Solution sol;
  vector<int> nums{1, 2, 3, 4, 5};
  vector<int> expect{1, 4, 3, 2, 5};

  ListNode *head = vec2list(nums);

  ListNode* actual = sol.reverseBetween(head, 2, 4);

  EXPECT_EQ(list2vec(actual), expect);

  delete head;
}

TEST(kk, t2) {
  Solution sol;
  vector<int> nums{1};
  vector<int> expect{1};

  ListNode *head = vec2list(nums);

  ListNode* actual = sol.reverseBetween(head, 1, 1);

  EXPECT_EQ(list2vec(actual), expect);

  delete head;
}

TEST(kk, t3) {
  Solution sol;
  vector<int> nums{1, 2, 3, 4, 5};
  vector<int> expect{4, 3, 2, 1, 5};

  ListNode *head = vec2list(nums);

  ListNode* actual = sol.reverseBetween(head, 1, 4);

  EXPECT_EQ(list2vec(actual), expect);

  delete actual;
}

