# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import unittest
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        cur = head
        target = None
        target_left = None
        while n > 0:
            cur = cur.next
            n -= 1
        target = head
        while cur:
            cur = cur.next
            target_left = target
            target = target.next
        if target_left:
            target_left.next = target.next
        if target == head:
            return head.next
        else:
            return head

if __name__ == "__main__":
    unittest.main()
