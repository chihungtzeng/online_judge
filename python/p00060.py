import unittest
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        fac = [1] * (n+1)
        for i in range(2, n+1):
            fac[i] = i * fac[i-1]
        k -= 1
        ret = 0
        ns = [_ for _ in range(1, n+1)]
        while n >= 1:
            index = int(k / fac[n-1])
            digit = ns.pop(index)
            ret = ret * 10 + digit
            k = k % fac[n-1]
            n = n - 1
        return str(ret)

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.getPermutation(3, 3), "213")
        self.assertEqual(sol.getPermutation(4, 9), "2314")

if __name__ == "__main__":
    unittest.main()
