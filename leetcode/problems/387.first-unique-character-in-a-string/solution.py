from collections import Counter


class Solution:
    def firstUniqChar(self, s: str) -> int:
        d = Counter(s)
        for ix, c in enumerate(s):
            if d[c] == 1:
                return ix
        return -1
