import unittest
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        import bisect
        n = len(numbers)
        prev = numbers[0] - 1
        for i in range(n):
            if numbers[i] == prev:
                continue
            prev = numbers[i]
            lookfor = target - numbers[i]
            i_1 = i + 1
            index = i_1 + bisect.bisect_left(numbers[i_1:], lookfor)
            if index < n and numbers[index] == lookfor:
                return [i_1, index+1]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        numbers = [2,7,11,15]
        target = 9
        self.assertEqual(sol.twoSum(numbers, target), [1, 2])
        numbers = [0, 0, 3, 4]
        target = 0
        self.assertEqual(sol.twoSum(numbers, target), [1, 2])

    def test_2(self):
        sol = Solution()
        numbers = [0] * 10000 + [2, 3] + [9]*10000
        target = 5
        self.assertEqual(sol.twoSum(numbers, target), [10001, 10002])

unittest.main()
