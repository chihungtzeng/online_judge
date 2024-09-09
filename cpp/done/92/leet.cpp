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
};
class Solution
{
public:
  ListNode* reverseBetween(ListNode* head, int left, int right)
  {
    ListNode *lnode = head, *prev_lnode = nullptr;
    for (int i = 1; i < left; i++)
    {
      prev_lnode = lnode;
      lnode = lnode->next;
    }
    ListNode* rnode = lnode;
    for (int j = right - left - 1; j >= 0; j--)
    {
      rnode = rnode->next;
    }
    ListNode* rnext = rnode->next;
    rnode->next = nullptr;
    reverse(lnode);
    if (prev_lnode)
    {
      prev_lnode->next = rnode;
    }
    else
    {
      head = rnode;
    }
    lnode->next = rnext;
    return head;
  }
  void reverse(ListNode* head)
  {
    ListNode *cur = head, *prev = nullptr;
    while (cur)
    {
      ListNode* temp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = temp;
    }
  }
};
