import unittest
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n <= 0:
            return []
        if n == 1:
            return ["()"]
        parens = self.generateParenthesis(n-1)
        ret = {}
        for paren in parens:
            ret["()" + paren] = 0
            ret[paren + "()"] = 0
            ret["(" + paren + ")"] = 0
        return list(ret.keys())
       

class SolTest(unittest.TestCase):
    def test_3(self):
        sol = Solution()
        print(sol.generateParenthesis(3))

    def test_4(self):
        sol = Solution()
        expected = ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
        self.assertEqual(sol.generateParenthesis(4), len(expected))
        


if __name__ == "__main__":
    unittest.main()
