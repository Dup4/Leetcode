from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = 0

        for t in zip(*strs):
            if len(set(t)) == 1:
                res += 1
            else:
                break

        return strs[0][:res]
