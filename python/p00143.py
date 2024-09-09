# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if not head:
            return
        mem = []
        cur = head
        while cur:
            mem.append(cur)
            cur = cur.next
        i = 0
        j = len(mem) - 1
        while i < j:
            mem[i].next = mem[j]
            i += 1
            if i < j:
                mem[j].next = mem[i]
            j -= 1
        mem[i].next = None
