class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip(" ")
        strs = s.split(" ")
        return len(strs[-1])
