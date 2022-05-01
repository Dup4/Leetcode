class Solution:
    def removeDigit(self, s: str, digit: str) -> str:
        cur_s = ""
        res = 0
        for i in range(len(s)):
            if s[i] == digit:
                cur_t = cur_s + s[i + 1:]
                res = max(res, int(cur_t))
            cur_s += s[i]
        return str(res)
