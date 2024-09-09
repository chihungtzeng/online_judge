class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        xs = "{}".format(x)
        return bool(xs == xs[::-1])

if __name__ == "__main__":
    sol = Solution()
    assert True == sol.isPalindrome(121)
    assert False == sol.isPalindrome(-121)
    assert False == sol.isPalindrome(10)
