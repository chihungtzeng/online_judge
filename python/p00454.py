import unittest
class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        import bisect
        n = len(A)
        s1 = [A[i] + B[j] for i in range(n) for j in range(n)]
        s2 = [C[i] + D[j] for i in range(n) for j in range(n)]
        count = 0
        s2.sort()
        s2len = len(s2)
        for num in s1:
            index = bisect.bisect_left(s2, -num)
            if index >= s2len or s2[index] != -num:
                continue
            index2 = bisect.bisect_right(s2, -num)
            count += index2 - index
        return count

class SolTest(unittest.TestCase):
    def test_1(self):
        A = [ 1, 2]
        B = [-2,-1]
        C = [-1, 2]
        D = [ 0, 2]
        sol = Solution()
        self.assertEqual(sol.fourSumCount(A, B, C, D), 2)

    def test_2(self):
        A = [-1,-1]
        B = [-1,1]
        C = [-1,1]
        D= [1,-1]
        sol = Solution()
        self.assertEqual(sol.fourSumCount(A, B, C, D), 6)

unittest.main()
