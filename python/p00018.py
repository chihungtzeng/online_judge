import unittest
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ret = {}
        nums.sort()

        two_sum = {}
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                _sum = nums[i] + nums[j]
                two_sum[_sum] = two_sum.get(_sum, set())
                two_sum[_sum].add((i, j))
        for _sum in two_sum:
            complement = target - _sum
            if complement < _sum:
                continue
            set1 = two_sum.get(_sum, None)
            set2 = two_sum.get(complement, None)
            if not set1 or not set2:
                continue
            for (u, v) in set1:
                for (x, y) in set2:
                    if self.has_duplicate(u, v, x, y):
                        continue
                    ans = [nums[u], nums[v], nums[x], nums[y]]
                    ans.sort()
                    ret[(ans[0], ans[1], ans[2], ans[3])] = 0
        return sorted([list(_) for _ in ret.keys()])

    def has_duplicate(self, u, v, x, y):
        return len(set([u, v, x, y])) < 4


class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        ret = sol.fourSum([1, 0, -1, 0, -2, 2], 0)
        self.assertEqual(len(ret), 3)

        ret = sol.fourSum([0, 0, 0, 0], 1)
        print(ret)
        self.assertEqual(len(ret), 0)
#        ans = [[-1,  0, 0, 1], [-2, -1, 1, 2], [-2,  0, 0, 2]]
#        self.assertEqual(set(ret), set(ans))

if __name__ == "__main__":
    unittest.main()
