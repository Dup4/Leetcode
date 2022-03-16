from typing import List


class Solution:
    def __init__(self) -> None:
        self.wd = {}
        self.n = 0
        self.res = []
        self.s = ""

    def dfs(self, idx: int, cur_str: str, cur_str_list: List[str]) -> None:
        if idx == self.n:
            if len(cur_str) == 0:
                self.res.append(" ".join(cur_str_list))
            return

        cur_str += self.s[idx]
        self.dfs(idx + 1, cur_str, cur_str_list)

        if cur_str in self.wd.keys():
            cur_str_list.append(cur_str)
            self.dfs(idx + 1, "", cur_str_list)
            cur_str_list.pop()

    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        self.s = s
        self.n = len(s)

        for w in wordDict:
            self.wd[w] = 1

        self.dfs(0, "", [])

        return self.res
