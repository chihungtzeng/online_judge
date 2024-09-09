# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return False
        turtle = head
        rabbit = head
        while turtle:
            turtle = turtle.next
            if rabbit:
                rabbit = rabbit.next
            if rabbit:
                rabbit = rabbit.next
            if turtle and rabbit and turtle == rabbit:
                return True
        return False

