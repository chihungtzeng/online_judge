import unittest
class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        stack = []
        nlen = len(num) - k
        for i in range(len(num)):
            while stack and k > 0 and num[i] < stack[-1]:
                stack.pop()
                k -= 1
            stack.append(num[i])
        start = next((i for i, n in enumerate(stack) if n != "0"), nlen)
#        print(stack, start)
        if start == nlen:
            return "0"
        else:
            return "".join(stack[start:start+nlen])


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.removeKdigits("1432219", 3), "1219")
        self.assertEqual(sol.removeKdigits("10200", 1), "200")
        self.assertEqual(sol.removeKdigits("10", 2), "0")
        self.assertEqual(sol.removeKdigits("9", 1), "0")
        self.assertEqual(sol.removeKdigits("112", 1), "11")


if __name__ == "__main__":
    unittest.main()

