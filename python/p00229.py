import unittest
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        majorities = {}
        for n in nums:
            if len(majorities) < 3:
                majorities[n] = 1 + majorities.get(n, 0)
            elif n in majorities:
                majorities[n] += 1
            else:
                ms = list(majorities.keys())
                for m in ms:
                    majorities[m] -= 1
                    if majorities[m] == 0:
                        majorities.pop(m, None)

        for m in majorities:
            majorities[m] = 0
        for n in nums:
            if n in majorities:
                majorities[n] += 1
        thresh = len(nums) / 3
        return sorted([_ for _ in majorities if majorities[_] > thresh])

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.majorityElement([3,2,3]), [3])
        self.assertEqual(sol.majorityElement([1, 2, 3]), [])
        self.assertEqual(sol.majorityElement([1,1,1,3,3,2,2,2]), [1, 2])
        self.assertEqual(sol.majorityElement([3, 1, 4, 1, 5, 9, 2, 6]), [])

    def test_2(self):
        nums = [6,53,53,96,45,79,53,58,53,90,40,53,53,1,53,53,89,53,33,27,53,53,84,42,53,53,87,51,66,53,28,53,53,53,50,39,36,48,19,74,38,53,42,53,99,53,80,53,53,53,53,96,78,52,24,53,53,53,53,64,10,53,53,53,53,82,53,53,53,22,53,53,67,53,53,53,53,53,67,53,19,99,53,53,21,53,69,53,53,53,52,53,96,53,53,51,81,62,4,6]
        sol = Solution()
        self.assertEqual(sol.majorityElement(nums), [53])

    def test_3(self):
        sol = Solution()
        nums = [1,2,0,4,5,0,6,7,8,9,9,9,9,9,9,0,0,0,0,0]
        print(len(nums))
        self.assertEqual(sol.majorityElement(nums), [0])

if __name__ == "__main__":
    unittest.main()
