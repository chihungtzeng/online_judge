# Definition for singly-linked list.
import unittest
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        odd_head = head
        odd_tail = head
        even_head = head.next if head else None
        even_tail = even_head
        is_odd = 1
        cur = even_tail.next if even_tail else None
        while cur:
            temp = cur.next
            if is_odd:
                odd_tail.next = cur
                odd_tail = cur
            else:
                even_tail.next = cur
                even_tail = cur
            is_odd = 1 - is_odd
            cur = temp
        if odd_tail:
            odd_tail.next = even_head
        if even_tail:
            even_tail.next = None
        return odd_head

class SolTest(unittest.TestCase):
    def gen_list(self, ell):
        if len(ell) == 0:
            return None
        nodes = [ListNode(v) for v in ell]
        for i in range(len(ell) - 1):
            nodes[i].next = nodes[i+1]
        nodes[len(ell) - 1].next = None
        return nodes[0]

    def show_nodes(self, head):
        cur = head
        ret = []
        while cur:
            print(cur.val, end=" ")
            ret.append(cur.val)
            cur = cur.next
        print("")
        return ret

    def test_0(self):
        ell = []
        head = self.gen_list(ell)
        self.show_nodes(head)
        sol = Solution()
        head = sol.oddEvenList(head)
        self.assertEqual(self.show_nodes(head), ell)

    def test_1(self):
        ell = [1]
        head = self.gen_list(ell)
        self.show_nodes(head)
        sol = Solution()
        head = sol.oddEvenList(head)
        self.assertEqual(self.show_nodes(head), ell)

    def test_2(self):
        ell = [1, 2]
        head = self.gen_list(ell)
        self.show_nodes(head)
        sol = Solution()
        head = sol.oddEvenList(head)
        self.assertEqual(self.show_nodes(head), ell)

    def test_3(self):
        ell = [1, 2, 3]
        head = self.gen_list(ell)
        self.show_nodes(head)
        sol = Solution()
        head = sol.oddEvenList(head)
        self.assertEqual(self.show_nodes(head), [1, 3, 2])

    def test_n(self):
        for n in range(4, 100):
            print("n = {}".format(n))
            ell = list(range(1, n+1))
            head = self.gen_list(ell)
            self.show_nodes(head)
            sol = Solution()
            head = sol.oddEvenList(head)
            expect = [ell[_] for _ in range(len(ell)) if _ % 2 == 0] + [ell[_] for _ in range(len(ell)) if _ % 2 == 1]
            self.assertEqual(self.show_nodes(head), expect)

if __name__ == "__main__":
    unittest.main()
