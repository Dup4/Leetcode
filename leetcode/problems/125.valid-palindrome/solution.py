class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        filter(str.isalnum, s)
        return s == s[::-1]
