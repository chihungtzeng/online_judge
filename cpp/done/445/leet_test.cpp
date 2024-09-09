#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

void deleteList(ListNode *head){
  auto* cur = head;
  while(cur){
    auto* tmp = cur->next;
    delete cur;
    cur = tmp;
  }
}

vector<int> list2vec(ListNode* head){
  ListNode *cur = head;
  vector<int> ret;
  while(cur) {
    ret.push_back(cur->val);
    cur = cur->next;
  }
  return ret;
}

TEST(kk, t1) {
  Solution sol;
  vector<ListNode *> l1(4), l2(3);
  for(int i=0; i<4; i++){
    l1[i] = new ListNode(0);
  }
  for(int i=0; i<3; i++){
    l2[i] = new ListNode(0);
  }
  l1[0]->val = 9;
  l1[1]->val = 9;
  l1[2]->val = 0;
  l1[3]->val = 1;
  l2[0]->val = 3;
  l2[1]->val = 8;
  l2[2]->val = 7;
  for(int i=0; i<=2; i++){
    l1[i]->next = l1[i+1];
  }
  for(int i=0; i<=1; i++){
    l2[i]->next = l2[i+1];
  }

  std::vector<int> l1vals{9,9,0,1};
  EXPECT_EQ(list2vec(l1[0]), l1vals);

  ListNode *head = sol.addTwoNumbers(l1[0], l2[0]);
  std::vector<int> expect{1,0,2,8,8};
  EXPECT_EQ(list2vec(head), expect);
  deleteList(head);
  deleteList(l1[0]);
  deleteList(l2[0]);
}

