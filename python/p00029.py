import unittest
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        down = abs(divisor)
        up = abs(dividend)
        q = 0
        while up >= down:
            tmp = down
            shift = 0
            while tmp <= up:
                tmp <<= 1
                shift += 1
            tmp >>= 1
            shift -= 1
            q += (1 << shift)
            up -= tmp
        if divisor * dividend >= 0:
            if q >= 2**31:
                q = 2**31 - 1
            return q
        else:
            return -q

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.divide(10, 3), 3)
        self.assertEqual(sol.divide(7, -3), -2)
        self.assertEqual(sol.divide(-7, 3), -2)
        self.assertEqual(sol.divide(-7, -3), 2)
        self.assertEqual(sol.divide(1, 1), 1)
        self.assertEqual(sol.divide(-2147483648, -1), 2147483647)
        self.assertEqual(sol.divide(-2147483648, 1), -2147483648)

unittest.main()

