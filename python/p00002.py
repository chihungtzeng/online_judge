# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def __parse_num(self, ln):
        radix = 1
        ret = 0
        while ln:
            ret += ln.val * radix
            radix *= 10
            ln = ln.next
        return ret

    def __encode(self, num):
        done = False
        next_ln = None
        while not done:
            least = num % 10
            num = num // 10
            node = ListNode(least)
            node.next = next_ln
            next_ln = node
            if num == 0:
                done = True
        return self.__reverse(next_ln)

    def __reverse(self, ln):
        cur_ln = ln
        prev_ln = None
        while cur_ln:
            temp = cur_ln.next

            cur_ln.next = prev_ln

            prev_ln = cur_ln
            cur_ln = temp
        return prev_ln

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        n1 = self.__parse_num(l1)
        n2 = self.__parse_num(l2)
        return self.__encode(n1 + n2)
