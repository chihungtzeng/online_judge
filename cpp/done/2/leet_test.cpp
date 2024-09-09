#include <cassert>
#include "leet.cpp"
#include <gtest/gtest.h>
#include "glog/stl_logging.h"
#include "glog/logging.h"

TEST(kk, t1)
{
  Solution sol;
  ListNode *l1, *l2;
  l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);
  l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);
  auto res = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(res->to_str(), "708");
  delete l1;
  delete l2;
  if (res) delete res;
}

TEST(kk, t2)
{
  Solution sol;
  ListNode *l1, *l2;
  l1 = new ListNode(0);
  l2 = new ListNode(0);
  auto res = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(res->to_str(), "0");
  delete l1;
  delete l2;
  if (res) delete res;
}

TEST(kk, t3)
{
  Solution sol;
  ListNode *l1, *l2;
  l1 = new ListNode(5);
  l2 = new ListNode(8);
  auto res = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(res->to_str(), "31");
  delete l1;
  delete l2;
  if (res) delete res;
}

TEST(kk, t4)
{
  Solution sol;
  ListNode *l1, *l2;
  l1 = new ListNode(9);
  l1->next = new ListNode(9);
  l1->next->next = new ListNode(9);
  l1->next->next->next = new ListNode(9);
  l1->next->next->next->next = new ListNode(9);
  l1->next->next->next->next->next = new ListNode(9);
  l1->next->next->next->next->next->next = new ListNode(9);

  l2 = new ListNode(9);
  l2->next = new ListNode(9);
  l2->next->next = new ListNode(9);
  l2->next->next->next = new ListNode(9);
  auto res = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(res->to_str(), "89990001");
  delete l1;
  delete l2;
  if (res) delete res;
}

