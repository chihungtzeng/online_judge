import unittest
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        if "res" not in self.__dict__:
            import heapq
            q = [1]
            ugly = {1: 0}
            done = False
            ms = [2, 3, 5]
            while not done:
                n_ = heapq.heappop(q)
                for m in ms:
                    nm = n_ * m
                    if nm not in ugly:
                        heapq.heappush(q, nm)
                        ugly[nm] = 0
                if len(ugly) > 2000:
                    done = True
            res = sorted(list(ugly.keys()))
        return res[n-1]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.nthUglyNumber(10), 12)
        self.assertEqual(sol.nthUglyNumber(1352), 402653184)

if __name__ == "__main__":
    unittest.main()
