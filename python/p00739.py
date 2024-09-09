import unittest
class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        recent = [float("inf")] * 102
        n = len(T)
        ans = [0] * n
        for cur_day in range(n-1, -1, -1):
            cur_day_temp = T[cur_day]
            cloest = min(recent[cur_day_temp+1:])
            if cloest == float("inf"):
                res = 0
            else:
                res = cloest - cur_day
            recent[cur_day_temp] = cur_day
            ans[cur_day] = res
        return ans

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.dailyTemperatures( [73, 74, 75, 71, 69, 72, 76, 73]), [1, 1, 4, 2, 1, 1, 0, 0])
        T = [89,62,70,58,47,47,46,76,100,70]
        self.assertEqual(sol.dailyTemperatures(T), [8,1,5,4,3,2,1,1,0,0])

unittest.main()
