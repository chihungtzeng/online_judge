import re
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        rgx = re.compile("^{}$".format(p))
        return bool(rgx.match(s))
        
if __name__ == "__main__":
    sol = Solution()
    assert False == sol.isMatch("aa", "a")
    assert True == sol.isMatch("aa", "a*")
    assert True == sol.isMatch("ab", ".*")
    assert True == sol.isMatch("aab", "c*a*b")
    assert False == sol.isMatch("mississippi", "mis*is*p*.")
