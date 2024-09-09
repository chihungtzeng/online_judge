import unittest
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        cache = {}
        candidates.sort(reverse=True)
        return [list(_) for _ in self.my_solve(candidates, target, cache)]

    def my_solve(self, candidates, target, cache):
        if target <= 0:
            return []
        if target in cache:
            return cache[target]
        ret = {}
        for can in candidates:
            if can > target:
                continue
            if can == target:
                ret[(can,)] = 1
                continue
            diff = target - can
            if diff in cache:
                sol_diff = cache[diff]
            else:
                sol_diff = self.my_solve(candidates, diff, cache)
            if sol_diff:
                for ell in sol_diff:
                    ret[ell + (can,)] = 1
        res = {}
        for t in ret:
            s = list(t)
            s.sort()
            res[tuple(s)] = 1
        cache[target] = list(res.keys())
        return cache[target]

class SolTest(unittest.TestCase):
    def test_1(self):
        candidates = [2,3,6,7]
        target = 7
        sol = Solution()
        print(sol.combinationSum(candidates, target))
        print(sol.combinationSum(candidates, 2))

        candidates = [2,3,5]
        target = 8
        print(sol.combinationSum(candidates, target))

unittest.main()
