import unittest
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        n = len(s)
        d = {}
        for i in range(n-9):
            t = s[i:i+10]
            d[t] = 1 + d.get(t, 0)
        return [key for key, _ in d.items() if _ > 1]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        dna = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
        expected = ["AAAAACCCCC", "CCCCCAAAAA"]
        self.assertEqual(sol.findRepeatedDnaSequences(dna), sorted(expected))
        dna = "A" * 9
        self.assertEqual(sol.findRepeatedDnaSequences(dna), [])
        dna = "A" * 10
        self.assertEqual(sol.findRepeatedDnaSequences(dna), [])
        dna = "A" * 11
        self.assertEqual(sol.findRepeatedDnaSequences(dna), ["A" * 10])

unittest.main()
