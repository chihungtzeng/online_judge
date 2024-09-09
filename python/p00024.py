# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        tail = None
        left = head
        right = head.next
        new_head = head.next
        while left and right:
            left.next = right.next
            right.next = left
            if tail:
                tail.next = right
            tail = left
            left = tail.next
            if left:
                right = left.next
        return new_head

        
