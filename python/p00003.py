class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_len = 0
        idx = 0
        while idx < len(s):
            offset, cur_max = self.lss_at(s[idx:])
            max_len = max(cur_max, max_len)
            idx += offset
        return max_len

    def lss_at(self, s):
        seen = {}
        length = 0
        for idx, char in enumerate(s):
            if char in seen:
                return seen[char] + 1, length
            else:
                length += 1
                seen[char] = idx
        return length, length

if __name__ == "__main__":
    sol = Solution()
    print(sol.lengthOfLongestSubstring("abcabcbb"))
    print(sol.lengthOfLongestSubstring("bbbbb"))
    print(sol.lengthOfLongestSubstring("pwwkew"))

