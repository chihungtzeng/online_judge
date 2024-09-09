import unittest
class Solution(object):
    def reduce(self, nums, ops, n, op):
        if ops and ops[-1] == "*":
            n2 = nums.pop()
            ops.pop()
            nums.append(n2 * n)
        elif ops and ops[-1] == "/":
            n2 = nums.pop()
            ops.pop()
            nums.append(n2 / n)
        else:
            nums.append(n)

        if op:
            ops.append(op)

    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        ops = []
        nums = []
        n = 0
        for char in s:
            if char == " ":
                continue
            elif char.isdigit():
                n = n * 10 + int(char)
            else:
                self.reduce(nums, ops, n, char)
                n = 0

        if n > 0 or len(nums) != len(ops) + 1:
            self.reduce(nums, ops, n, None)
        ret = nums[0]
        for i in range(len(ops)):
            op = ops[i]
            n = nums[i+1]
            if op == "+":
                ret += n
            else:
                ret -= n
        return ret

class SolTest(unittest.TestCase):
    def test_0(self):
        sol  = Solution()
        self.assertEqual(sol.calculate("1-1+1"), 1)
    def test_1(self):
        sol  = Solution()
        self.assertEqual(sol.calculate("1-1+1"), 1)
        self.assertEqual(sol.calculate("1*2*3*4"), 24)
        self.assertEqual(sol.calculate("1*2*3*4 + 0"), 24)
        self.assertEqual(sol.calculate("3+2*2"), 7)
        self.assertEqual(sol.calculate(" 3/2 "), 1)
        self.assertEqual(sol.calculate(" 3+5 / 2 "), 5)

unittest.main()
