import unittest
class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for token in tokens:
            if token.isdigit() or (token[0] == "-" and token[1:].isdigit()):
                stack.append(int(token))
            else:
                n1 = stack.pop()
                n2 = stack.pop()
                if token == "+":
                    stack.append(n1 + n2)
                elif token == "-":
                    stack.append(n2 - n1)
                elif token == "*":
                    stack.append(n2 * n1)
                else:
                    stack.append(int(float(n2) / n1))
        return stack[0]

class SolTest(unittest.TestCase):
    def test_1(self):
        sol = Solution()
        self.assertEqual(sol.evalRPN(["2", "1", "+", "3", "*"]), 9)
        self.assertEqual(sol.evalRPN(["4", "13", "5", "/", "+"]), 6)
        self.assertEqual(sol.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]), 22)

if __name__ == "__main__":
    unittest.main()
