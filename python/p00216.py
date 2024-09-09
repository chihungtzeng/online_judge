import unittest
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        def calc_sum(bits):
            num_bits_1 = 0
            digit = 1
            digits = []
            while bits > 0:
                if bits & 1:
                    digits.append(digit)
                    num_bits_1 += 1
                bits >>= 1
                digit += 1
            return num_bits_1, sum(digits), digits
        if "cache" not in self.__dict__:
            self.cache = {}
            for bits in range(2**9):
                _k, _sum, digits = calc_sum(bits)
                if (_k, _sum) not in self.cache:
                    self.cache[(_k, _sum)] = [digits]
                else:
                    self.cache[(_k, _sum)].append(digits)
        if (k, n) in self.cache:
            return sorted(self.cache[(k, n)])
        else:
            return []

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.combinationSum3(3, 7), [[1,2,4]])
        self.assertEqual(sol.combinationSum3(3, 9), [[1,2,6], [1,3,5], [2,3,4]])
        self.assertEqual(sol.combinationSum3(3, 2), [])

if __name__ == "__main__":
    unittest.main()
