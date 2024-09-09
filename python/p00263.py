import unittest
class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        done = False
        while not done:
            done = True
            if num % 2 == 0:
                num >>= 1
                done = False
            if num % 3 == 0:
                num = num / 3
                done = False
            if num % 5 == 0:
                num = num / 5
                done = False
        return bool(num == 1)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertTrue(sol.isUgly(6))
        self.assertTrue(sol.isUgly(8))
        self.assertFalse(sol.isUgly(14))
        self.assertTrue(sol.isUgly(2147483648))
        self.assertFalse(sol.isUgly(-2147483648))

if __name__ == "__main__":
    unittest.main()
