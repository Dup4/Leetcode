from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        odd = 0
        res = 0
        for v in c.values():
            res += v // 2 * 2
            if v & 1:
                odd = 1
        return res + odd
