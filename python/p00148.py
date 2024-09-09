import unittest
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if (not head) or (not head.next):
            return head
        half = self.cut_half(head)
        half = self.sortList(half)
        head = self.sortList(head)
        ret = self.merge(head, half)
        return ret

    def cut_half(self, head):
        slow = head
        fast = head
        slow_pre = None
        while fast and fast.next:
            fast = fast.next.next
            slow_pre = slow
            slow = slow.next
        slow_pre.next = None
        return slow

    def merge(self, s1, s2):
        if s1.val < s2.val:
            head = s1
            s1 = s1.next
        else:
            head = s2
            s2 = s2.next
        tail = head
        while s1 and s2:
            if s1.val < s2.val:
                tail.next = s1
                s1 = s1.next
            else:
                tail.next = s2
                s2 = s2.next
            tail = tail.next
        while s1:
            tail.next = s1
            tail = tail.next
            s1 = s1.next
        while s2:
            tail.next = s2
            tail = tail.next
            s2 = s2.next
        return head

    def dump(self, head):
        cur = head
        ret = []
        while cur:
            ret.append(cur.val)
            cur = cur.next
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        nodes = [ListNode(_) for _ in [4, 2, 1, 3]]
        for i in range(3):
            nodes[i].next = nodes[i+1]
        head = sol.sortList(nodes[0])
        ret = sol.dump(head)
        self.assertEqual(ret, [1, 2, 3, 4])

    def test_2(self):
        sol = Solution()
        vals = [-1, 5, 3, 4, 0]
        nodes = [ListNode(_) for _ in vals]
        for i in range(len(vals) - 1):
            nodes[i].next = nodes[i+1]
        head = sol.sortList(nodes[0])
        ret = sol.dump(head)
        self.assertEqual(ret, sorted(vals))

    def test_3(self):
        sol = Solution()
        head = sol.sortList(None)
        ret = sol.dump(head)
        self.assertEqual(ret, [])

    def test_4(self):
        sol = Solution()
        node = ListNode(5)
        head = sol.sortList(node)
        ret = sol.dump(head)
        self.assertEqual(ret, [5])




unittest.main()

