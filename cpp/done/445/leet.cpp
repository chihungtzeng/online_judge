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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
  /*
  ~ListNode() {
    if (next) {
      delete next;
      next = nullptr;
    }
  }
  */
};
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    int carry = 0;
    while (l1 || l2) {
      int n1 = 0, n2 = 0;
      if (l1) {
        n1 = l1->val;
        l1 = l1->next;
      }
      if (l2) {
        n2 = l2->val;
        l2 = l2->next;
      }
      int sum = n1 + n2 + carry;
      if (!cur) {
        head = new ListNode(sum % 10);
        cur = head;
      } else {
        ListNode* tmp = new ListNode(sum % 10);
        cur->next = tmp;
        cur = tmp;
      }
      carry = sum / 10;
    }
    if (carry) {
      ListNode* tmp = new ListNode(carry);
      cur->next = tmp;
    }
    return reverse(head);
  }
  ListNode* reverse(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = nullptr;
    while (cur) {
      ListNode* tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }
    return prev;
  }
};
