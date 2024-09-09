#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr)
  {
  }
  ListNode(int x) : val(x), next(nullptr)
  {
  }
  ListNode(int x, ListNode* next) : val(x), next(next)
  {
  }
  ~ListNode()
  {
    if (next)
    {
      delete next;
      next = nullptr;
    }
  }
  string to_str()
  {
    string suffix = "";
    if (next)
    {
      suffix = next->to_str();
    }
    return to_string(val) + suffix;
  }
};
class Solution
{
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    int carry = 0;
    ListNode *head = nullptr, *tail = nullptr;
    while (l1 || l2)
    {
      int val = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      carry = val / 10;
      val = val % 10;
      ListNode* new_node = new ListNode(val);
      if (!head)
      {
        head = new_node;
      }
      if (tail)
      {
        tail->next = new_node;
      }
      tail = new_node;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    if (carry > 0 && tail)
    {
      tail->next = new ListNode(carry);
    }
    return head;
  }
};
