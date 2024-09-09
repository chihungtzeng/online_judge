import unittest
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        return [list(_) for _ in self.solve(candidates, target)]

    def solve(self, candidates, target):
        print(candidates, target)
        if target <= 0 or not candidates:
            return []
        v = candidates[0]
        if target  < v:
            return []
        if target == v:
            return {(v,): 1}
        ret = {}
        sol = self.solve(candidates[1:], target - v)
        if sol:
            for item in sol:
                ret[item + (v,)] = 1
        for key in self.solve(candidates[1:], target):
            ret[key] = 1
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        print(sol.combinationSum2([10,1,2,7,6,1,5], 8))
        print(sol.combinationSum2([2,5,2,1,2], 5))

unittest.main()
