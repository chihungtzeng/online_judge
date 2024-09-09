import collections
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        ## RC ##
        ## APPROACH : RECURSION ##
        ## LOGIC ##
        # The idea is that any characters in the string that do not satisfy the requirement break the string in multiple parts that do not contain these characters, and for each part we should check the requirement again.
        # Concerning complexity, it is indeed formally O(N), like it was mentioned in another solution despite recursion, because at each level of recursion we look at maximum 2N characters, and there can be not more than 26 levels of recursion, because we remove at least one character from 26 possible characters each time we move to the next level.

        cnt = collections.Counter(s)
        st = 0
        maxst = 0
        for i, c in enumerate(s):
            if cnt[c] < k:
                maxst = max(maxst, self.longestSubstring(s[st:i], k))
                st = i + 1
        return len(s) if st == 0 else max(maxst, self.longestSubstring(s[st:], k))

sol = Solution()
s = "zzzzzzzzzzaaaaaaaaabbbbbbbbhbhbhbhbhbhbhicbcbcibcbccccccccccbbbbbbbbaaaaaaaaafffaahhhhhiaahiiiiiiiiifeeeeeeeeee"
print(sol.longestSubstring(s, 10))
print(s.find("bcbccccccccccbbbbbbbb"))
print(s[47:21+47])
