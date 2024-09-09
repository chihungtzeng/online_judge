# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        turtle = head
        rabbit = head
        while turtle:
            turtle = turtle.next
            if rabbit:
                rabbit = rabbit.next
            if rabbit:
                rabbit = rabbit.next
            if turtle and rabbit and turtle == rabbit:
                return self.find_loop(head, rabbit)
        return None

    def find_loop(self, head, rabbit):
        turtle = head
        while rabbit != turtle:
            turtle = turtle.next
            rabbit = rabbit.next
        return rabbit
