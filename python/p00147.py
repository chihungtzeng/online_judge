import unittest
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if (not head) or (not head.next):
            return head
        self.head = head
        self.sorted_tail = head
        cur = self.sorted_tail.next
        while cur:
            self.move_node(cur)
            cur = self.sorted_tail.next
        return self.head

    def move_node(self, node):
        prev = None
        pivot = self.head
        while pivot and pivot.val < node.val and pivot is not node:
            prev = pivot
            pivot = pivot.next
        if pivot is node:
            self.sorted_tail = node
        else:
            self.sorted_tail.next = node.next
            node.next = pivot
            if prev:
                prev.next = node
            else:
                self.head = node



class SolTest(unittest.TestCase):
    def dump(self, head):
        cur = head
        ret = []
        while cur:
            ret.append(cur.val)
            cur = cur.next
        return ret

    def test_1(self):
        sol = Solution()
        vals = [4,2,1,3]
        nodes = [ListNode(_) for _ in vals]
        for i in range(len(vals) - 1):
            nodes[i].next = nodes[i+1]
        head = sol.insertionSortList(nodes[0])
        ret = self.dump(head)
        self.assertEqual(ret, sorted(vals))

    def test_2(self):
        sol = Solution()
        vals = [-1, 5, 3, 4, 0]
        nodes = [ListNode(_) for _ in vals]
        for i in range(len(vals) - 1):
            nodes[i].next = nodes[i+1]
        head = sol.insertionSortList(nodes[0])
        ret = self.dump(head)
        self.assertEqual(ret, sorted(vals))

unittest.main()
