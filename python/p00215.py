import unittest
class Solution(object):
    def findKthLargest(self, nums, k):
        nums.sort()
        return nums[-k]

    def -findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if len(nums) == 1 and k == 1:
            return nums[0]
        pivot = nums[0]
        lts, eqs, gts = [], [], []
        for n in nums:
            if n < pivot:
                lts.append(n)
            elif n == pivot:
                eqs.append(n)
            else:
                gts.append(n)
        if len(gts) >= k:
            return self.findKthLargest(gts, k)
        elif len(eqs) >= k - len(gts):
            return pivot
        else:
            return self.findKthLargest(lts, k - len(gts) - len(eqs))

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.findKthLargest([3,2,1,5,6,4], 2), 5)
        self.assertEqual(sol.findKthLargest([3,2,3,1,2,4,5,5,6], 4), 4)

    def test_2(self):
        sol = Solution()
        nums = list(range(1, 10000 + 1))
        import random
        random.shuffle(nums)
        for i in range(1, 10000):
            self.assertEqual(sol.findKthLargest(nums, i), 10001 - i)

if __name__ == "__main__":
    unittest.main()
