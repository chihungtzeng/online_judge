import unittest
class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        orda = ord("a")
        def word2num(word):
            n = 0
            for c in word:
                n |= 1 << (ord(c) - orda)
            return n
        lens = [len(word) for word in words]
        nums = [word2num(word) for word in words]
        ret = 0
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if nums[i] & nums[j] == 0:
                    ret = max(ret, lens[i] * lens[j])
        return ret

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        words = ["a","ab","abc","d","cd","bcd","abcd"]
        self.assertEqual(sol.maxProduct(words), 4)
        words = ["a","aa","aaa","aaaa"]
        self.assertEqual(sol.maxProduct(words), 0)

if __name__ == "__main__":
    unittest.main()
