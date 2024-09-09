import unittest
import pdb
class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        self.maxChoosableInteger = maxChoosableInteger
        if desiredTotal == 0 and maxChoosableInteger >= 1:
            return True
        if desiredTotal > (maxChoosableInteger * (maxChoosableInteger + 1) >> 1):
            return False
        choosable = (1 << maxChoosableInteger) - 1
        dp = {}
        self.calc_dp(dp, choosable, desiredTotal)
#        print(dp)
        return dp[(choosable, desiredTotal)]

    def calc_dp(self, dp, choosable, desiredTotal):
#        print(choosable, desiredTotal)
#        pdb.set_trace()
        if choosable == 0 or desiredTotal <= 0:
            dp[(choosable, desiredTotal)] = False
            return False
        ret = False
        for c in range(1, self.maxChoosableInteger + 1):
            if choosable & (1 << (c-1)) == 0:
                continue
            if c >= desiredTotal:
                ret = True
            mask_c = choosable & (~(1 << (c-1)))
            if (mask_c, desiredTotal - c) not in dp:
                self.calc_dp(dp, mask_c, desiredTotal - c)
            if not dp[(mask_c, desiredTotal - c)]:
                ret = True
            # print(c, desiredTotal, " -> ", ret)
            if ret:
                break
        dp[(choosable, desiredTotal)] = ret
        return ret

 
class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertFalse(sol.canIWin(10, 11))
        for total in range(1, 11):
            self.assertTrue(sol.canIWin(10, total))
        self.assertTrue(sol.canIWin(10, 12))
#        self.assertTrue(sol.canIWin(18, 79))
        self.assertFalse(sol.canIWin(10, 40))
    def test_2(self):
        sol = Solution()
        self.assertTrue(sol.canIWin(10, 1))
        self.assertTrue(sol.canIWin(10, 0))
        self.assertFalse(sol.canIWin(10, 65))
        self.assertFalse(sol.canIWin(5, 50))

if __name__ == "__main__":
    unittest.main()
